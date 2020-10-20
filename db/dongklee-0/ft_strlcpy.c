/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:57:06 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 17:23:26 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	idx;
	size_t	len_src;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	idx = 0;
	while ((idx < len_src) && (idx + 1) < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (len_src);
}
