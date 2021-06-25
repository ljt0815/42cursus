/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:07:13 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/06 19:49:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	int				size;
	int				i;

	i = 0;
	temp = (unsigned char *)s;
	size = (int)n;
	while (i < size)
	{
		*(temp + i) = 0;
		i++;
	}
}
