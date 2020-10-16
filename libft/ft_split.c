/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:58:49 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/16 18:41:55 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_result(char const *s, char c, int cnt, char **result)
{
	int		i;
	int		start;
	int		idx;

	i = 0;
	idx = 0;
	while (idx < cnt)
	{
		start = -1;
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i])
			start = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		if (start != -1)
		{
			if ((result[idx] = (char *)malloc(i - start + 2)) == 0)
				return ;
			ft_strlcpy(result[idx], s + start, i - start + 1);
			idx++;
		}
	}
	result[cnt] = 0;
}

char	**null_process(char c, char **result, char const *s)
{
	if (c == 0)
	{
		if((result = (char **)malloc(sizeof(char *) * 2)))
			return (0);
		result[0] = ft_strdup(s);
		result[1] = 0;
		return (result);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	**result;

	result = 0;
	cnt = 0;
	i = 0;
	if ((result = null_process(c, result, s)))
		return (result);
	while (s[i])
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i])
			cnt++;
		while (s[i] != 0 && s[i] != c)
			i++;
	}
	if ((result = (char **)malloc(sizeof(char *) * (cnt + 1))) == 0)
		return (0);
	make_result(s, c, cnt, result);
	return (result);
}
