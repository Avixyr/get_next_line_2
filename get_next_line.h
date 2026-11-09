/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artbaudo <artbaudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:55:15 by artbaudo          #+#    #+#             */
/*   Updated: 2026/11/06 16:42:58 by artbaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strmerge(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strldup(const char *s, int size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);

#endif