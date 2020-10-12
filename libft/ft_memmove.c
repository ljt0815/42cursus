/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:34:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/12 17:28:59 by jitlee           ###   ########.fr       */
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
	i = 0;
	new_dst = (char *)dst;
	new_src = (const char *)src;
	if (dst <= src)
		while (i < len)
		{
			new_dst[i] = new_src[i];
			i++;
		}
	else
		while (i < len)
		{
			new_dst[len - (i + 1)] = new_src[len - (i + 1)];
			i++;
		}
	return (dst);
}
