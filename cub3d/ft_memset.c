/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:21:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/04 01:33:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned int	i;
	unsigned int	i_len;

	i_len = (unsigned int)len;
	temp = (unsigned char *)b;
	i = 0;
	while (i < i_len)
	{
		*(temp + i) = c;
		i++;
	}
	return (b);
}
