/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artbaudo <artbaudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:11:02 by artbaudo          #+#    #+#             */
/*   Updated: 2026/11/06 16:41:58 by artbaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_strldup(const char *s, int size)
{
	int		i;
	int		len;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (len > size)
		len = size;
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	size_t	res;

	len_s = ft_strlen(src);
	len_d = 0;
	while (len_d < size && dest[len_d])
		len_d++;
	res = len_s + size;
	if (size > len_d)
		res = len_d + len_s;
	if (size < 1)
		return (len_s + size);
	i = 0;
	while (src[i] && len_d < size - 1)
	{
		dest[len_d] = src[i];
		i++;
		len_d++;
	}
	if (len_d != size)
		dest[len_d] = '\0';
	return (res);
}

char	*ft_strmerge(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	if (!s2)
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(mem + i) = 0;
		i++;
	}
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if ((char)c == s[i])
		return ((char *)s + i);
	return (0);
}
