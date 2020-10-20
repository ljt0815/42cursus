/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:30:23 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 16:36:39 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcnt(const char *s, char c)
{
	size_t	idx;
	size_t	words;

	idx = 0;
	words = 0;
	while (s[idx])
	{
		if (s[idx] != c)
			words++;
		while (s[idx] != c && s[idx + 1])
			idx++;
		idx++;
	}
	return (words);
}

size_t	ft_wordlen(const char *s, char c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (s[idx] == c)
		idx++;
	while (s[idx] != c && s[idx++])
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**res;

	i = 0;
	k = 0;
	if (!s || !(res = (char **)malloc(sizeof(char *) *
		(ft_wordcnt(s, c) + 1))))
		return (0);
	while (i < ft_wordcnt(s, c))
	{
		if (!(res[i] = (char *)malloc(sizeof(char) *
			(ft_wordlen(&s[k], c) + 1))))
			return (0);
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			res[i][j++] = s[k++];
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
