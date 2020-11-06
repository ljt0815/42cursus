/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:49:48 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/07 00:51:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (src[len] != 0)
		len++;
	if (size == 0)
		return (len);
	if (len < size)
	{
		while (++i < len)
			dest[i] = src[i];
		dest[i] = 0;
		return (len);
	}
	else
	{
		while (++i < size - 1)
			dest[i] = src[i];
		if (size != 0)
			dest[i] = 0;
		return (len);
	}
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	while (src[j] != 0)
		j++;
	if (i < size)
		return (i + j);
	else
		return (size + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	if ((result = (char *)malloc(s1_len + s2_len + 1)) == 0)
		return (0);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;
	int				i;

	i = 0;
	find = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (find == 0)
		return ((char *)s + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (s_len <= start)
	{
		if ((result = (char *)malloc(1)) == 0)
			return (0);
		result[0] = 0;
		return (result);
	}
	if ((result = (char *)malloc(len + 1)) == 0)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
