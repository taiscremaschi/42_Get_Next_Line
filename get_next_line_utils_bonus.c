/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:59:29 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/05/06 18:59:29 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
	{
		return (0);
	}
	while (s[x])
		x++;
	return (x);
}

int	ft_check(char *b)
{
	int	i;
	int	inicial;
	int	newline;

	newline = 0;
	i = 0;
	inicial = 0;
	while (b[i])
	{
		if (newline)
			b[inicial++] = b[i];
		if (b[i] == '\n')
			newline = 1;
		b[i++] = '\0';
	}
	return (newline);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		posi;
	char	*result;

	if (s2[0] == '\0')
		return (0);
	i = 0;
	posi = -1;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[++posi])
	{
		result[i++] = s2[posi];
		if (s2[posi] == '\n')
			break ;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}
