/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:35:32 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/07 17:12:12 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*find;
	size_t			i;

	i = 0;
	find = (unsigned char *)s;
	while (i < n)
	{
		if (*(find + i) == c)
			return (find + i);
		i++;
	}
	return (0);
}
