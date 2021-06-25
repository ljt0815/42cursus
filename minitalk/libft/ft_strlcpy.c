/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:42:54 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/08 19:25:34 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (src[len] != 0)
		len++;
	if (size == 0)
		return (len);
	if (len < size)
	{
		while (++i < len)
			dest[i] = src[i];
		dest[i] = 0;
		return (len);
	}
	else
	{
		while (++i < size - 1)
			dest[i] = src[i];
		if (size != 0)
			dest[i] = 0;
		return (len);
	}
	return (0);
}
