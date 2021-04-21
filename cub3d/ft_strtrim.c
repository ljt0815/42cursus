/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:41:11 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/11 22:11:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_idx(const char *src, const char *findset, int flag)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(src);
	if (flag == 1)
	{
		while (++i < len)
			if (ft_strchr(findset, src[i]) == 0)
				break ;
		return (i);
	}
	else if (flag == 2)
	{
		while (++i < len)
			if (ft_strchr(findset, src[len - i - 1]) == 0)
				break ;
		return (len - i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (set == 0)
		return (ft_strdup(s1));
	start = get_idx(s1, set, 1);
	end = get_idx(s1, set, 2);
	if (start >= end)
		return (ft_strdup(""));
	if ((result = (char *)malloc(end - start + 1)) == 0)
		return (0);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
