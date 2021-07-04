/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:34:04 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 00:10:45 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*new_dst;
	const char	*new_src;
	size_t		i;

	if ((dst == 0 && src == 0) || len == 0)
		return (dst);
	i = -1;
	new_dst = (char *)dst;
	new_src = (const char *)src;
	if (dst <= src)
		while (++i < len)
			new_dst[i] = new_src[i];
	else
		while (++i < len)
			new_dst[len - (i + 1)] = new_src[len - (i + 1)];
	return (dst);
}
