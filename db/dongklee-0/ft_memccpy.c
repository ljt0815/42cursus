/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:25:38 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:42:54 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,\
					int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	idx = 0;
	if (!dst && !src)
		return (0);
	while (idx < n)
	{
		d[idx] = s[idx];
		if (d[idx] == (unsigned char)c)
			return (d + idx + 1);
		idx++;
	}
	return (0);
}
