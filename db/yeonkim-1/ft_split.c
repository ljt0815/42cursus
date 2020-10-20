/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:28:18 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/16 19:11:29 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret);
	ret = NULL;
}

static char	*ft_split_strdup(const char *s, char c)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	if (!(ptr = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

static char	**malloc_words(char **ret, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			if (!(ret[j++] = ft_split_strdup(&s[i], c)))
			{
				free_words(ret);
				return (NULL);
			}
		while (s[i] != c && s[i])
			i++;
	}
	return (ret);
}

static char	**malloc_array(char const *s, char c)
{
	char	**ret;
	int		i;
	int		word_num;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			word_num++;
		while (s[i] != c && s[i])
			i++;
	}
	if (!(ret = ft_calloc(word_num + 1, sizeof(char *))))
		return (NULL);
	if (!(ret = malloc_words(ret, s, c)))
		return (NULL);
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	if (!(ret = malloc_array(s, c)))
		return (NULL);
	return (ret);
}
