/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:03:58 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:37:55 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;
	size_t			idx;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (cp_s1[idx] != cp_s2[idx])
			return (cp_s1[idx] - cp_s2[idx]);
		idx++;
	}
	return (0);
}
