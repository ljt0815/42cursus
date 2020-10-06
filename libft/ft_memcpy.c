/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:07:13 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/06 19:58:43 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*new_dst;
	char	*new_src;
	int		new_n;

	new_n = (int)n;
	new_dst = (char *)dst;
	new_src = (char *)src;
	i = 0;
	while (i < new_n)
	{
		*(new_dst + i) = *(new_src + i);
		i++;
	}
	return (dst);
}
