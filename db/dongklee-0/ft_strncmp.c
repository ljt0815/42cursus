/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:46:46 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 17:26:54 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	idx = 0;
	while (cp_s1[idx] && cp_s2[idx] && idx < n)
	{
		if (cp_s1[idx] != cp_s2[idx])
			return (cp_s1[idx] - cp_s2[idx]);
		idx++;
	}
	if (idx == n)
		return (0);
	return (cp_s1[idx] - cp_s2[idx]);
}
