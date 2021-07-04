/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:58:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 01:08:31 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	malloc_func(void *target, int size)
{
	void	**p;

	p = (void **)target;
	*p = malloc(size);
	if (*p == 0)
		return (0);
	return (1);
}

char	**ft_malloc_error(char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

int	make_result(char const *s, char c, int cnt, char **result)
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
			if (!malloc_func(&result[idx], i - start + 2))
				return (0);
			ft_strlcpy(result[idx], s + start, i - start + 1);
			idx++;
		}
	}
	result[cnt] = 0;
	return (1);
}

char	**null_process(char const *s, char c, char **result, int *iserror)
{
	if (c == 0)
	{
		if (*s == 0)
		{
			if (!malloc_func(&result, sizeof(char *)))
			{
				*iserror = 1;
				return (0);
			}
			result[0] = 0;
			return (result);
		}
		if (!malloc_func(&result, sizeof(char *) * 2))
		{
			*iserror = 1;
			return (0);
		}
		result[0] = ft_strdup(s);
		result[1] = 0;
		return (result);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		tmp;
	char	**result;

	result = 0;
	tmp = 0;
	i = 0;
	result = null_process(s, c, result, &tmp);
	if (result != 0 || tmp == 1)
		return (result);
	while (s[i])
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i])
			tmp++;
		while (s[i] != 0 && s[i] != c)
			i++;
	}
	if (!malloc_func(&result, sizeof(char *) * (tmp + 1)))
		return (0);
	if ((make_result(s, c, tmp, result)) == 0)
		return (ft_malloc_error(result));
	return (result);
}
