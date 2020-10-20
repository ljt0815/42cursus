/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:04:29 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 18:47:34 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_in_set(char a, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (a == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*front;
	char	*back;
	size_t	len;

	front = (char *)s1;
	back = front + ft_strlen(s1);
	while (*front && is_in_set(*front, set))
		front++;
	while ((front < back) && is_in_set(*(back - 1), set))
		back--;
	len = (back - front) + 1;
	if (!(result = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_strlcpy(result, front, len);
	return (result);
}
