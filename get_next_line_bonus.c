/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/05/06 18:59:36 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/05/06 18:59:36 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!buff[fd][0])
		buff[fd][read(fd, buff[fd], BUFFER_SIZE)] = 0;
	while (buff[fd][0])
	{
		line = ft_strjoin(line, buff[fd]);
		if (!line)
			return (NULL);
		if (ft_check(buff[fd]) != 0)
			break ;
		if (read(fd, buff[fd], 0) < 0)
		{
			free(line);
			return (NULL);
		}
		buff[fd][read(fd, buff[fd], BUFFER_SIZE)] = 0;
	}
	return (line);
}
