/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:52:35 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 16:36:23 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if ((dst == NULL) && (src == NULL))
		return (0);
	idx = 0;
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dst);
}
