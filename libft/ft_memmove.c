/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:34:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/06 21:45:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*new_dst;
	const char	*new_src;
	size_t		i;

	i = 0;
	new_dst = dst;
	new_src = src;
	if (dst <= src)
	{
		while (i < len)
		{
			new_dst[i] = new_src[i];
			i++;	
		}
	}
	else
	{
		new_dst += len;
		new_src += len;
		while (i < len)
		{
			new_dst[len - (i + 1)] = new_src[len - (i + 1)];
			i++;
		}
	}
	return (dst);
}
