/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:38:48 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/05/07 15:31:21 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!buff[0])
		buff[read(fd, buff, BUFFER_SIZE)] = 0;
	while (buff[0])
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_check(buff) != 0)
			break ;
		if (read(fd, buff, 0) < 0)
		{
			free(line);
			return (NULL);
		}
		buff[read(fd, buff, BUFFER_SIZE)] = 0;
	}
	return (line);
}

/*int main()
{
    int fd;
    char    *str;

    fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("-> %s", str);
    return(0);
}*/
