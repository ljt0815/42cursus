/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:15:02 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/08 20:56:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s_len;
	size_t	f_len;
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	s_len = ft_strlen(haystack);
	f_len = ft_strlen(needle);
	if (s_len < f_len || len < f_len)
		return (0);
	while (i < len && (len - i) >= f_len)
	{
		if (ft_memcmp(&haystack[i], &needle[0], f_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
