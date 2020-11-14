/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:46:09 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/13 23:34:37 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_s;

	my_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (my_s[i] == (unsigned char)c)
			return (my_s + i);
		i++;
	}
	return (0);
}

/*
** line 23 : declare my_s, because adding add value i to void * is impossible
** line 29 : explicitly cast c into unsigned char
*/
