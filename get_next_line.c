/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artbaudo <artbaudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:33:10 by artbaudo          #+#    #+#             */
/*   Updated: 2026/11/06 16:55:46 by artbaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		byte;
	int		i;
	int		j;
	char	*res;

	byte = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] && byte > 0)
	{
		if (buffer[i] == '\n')
			break;
		i++;
		if (i == byte)
		{
			if (buffer[i] == '\n')
				break;
			i = 0;
			byte = read(fd, buffer, BUFFER_SIZE);
		}
	}
	close(fd);
	if (buffer[i] != '\n')
		return (ft_strdup(buffer));
	else
	{
		res = malloc((i + 2)* sizeof(char));
		res[i + 1] = '\0';
		j = 0;
		while (j <= i)
		{
			res[j] = buffer[j];
			j++;
		}
		return (res);
	}
}