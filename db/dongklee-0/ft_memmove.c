/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:44:32 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:36:41 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*cp_dst;
	unsigned char	*cp_src;

	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	idx = 0;
	if (dst < src)
		while (idx < len)
		{
			cp_dst[idx] = cp_src[idx];
			idx++;
		}
	else
		while (idx < len)
		{
			cp_dst[len - idx - 1] = cp_src[len - idx - 1];
			idx++;
		}
	return (dst);
}
