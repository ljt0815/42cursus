/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:15:02 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/15 20:13:34 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	i = 0;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *)haystack);
	if (h_len < n_len || len < n_len)
		return (0);
	while (i < len && (len - i) >= n_len)
	{
		if (ft_memcmp(&haystack[i], &needle[0], n_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
