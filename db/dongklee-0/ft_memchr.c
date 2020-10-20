/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:01:45 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 16:33:14 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp_s;
	unsigned char	cp_c;
	size_t			idx;

	cp_s = (unsigned char *)s;
	cp_c = (unsigned char)c;
	idx = 0;
	while (idx < n)
	{
		if (cp_s[idx] == cp_c)
			return (cp_s + idx);
		idx++;
	}
	return (0);
}
