/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artbaudo <artbaudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:33:10 by artbaudo          #+#    #+#             */
/*   Updated: 2026/11/10 11:30:20 by artbaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_buffer(char *buffer)
{
	char	*clean;

	if (!buffer)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
	{
		free(buffer);
		return (NULL);
	}
	clean = ft_strdup(ft_strchr(buffer, '\n') + 1);
	free(buffer);
	return (clean);
}

char	*get_line(char *buffer)
{
	char	*res;
	int		i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*get_readline(char *buffer, int fd)
{
	int		byte;
	char	*temp;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
	{
		free(buffer);
		return (0);
	}
	byte = 1;
	while (buffer && byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(temp);
			free(buffer);
			return (0);
		}
		temp[byte] = '\0';
		buffer = ft_strmerge(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, sizeof(char));
	if (!buffer[fd])
		return (0);
	buffer[fd] = get_readline(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	res = get_line(buffer[fd]);
	buffer[fd] = clean_buffer(buffer[fd]);
	return (res);
}
