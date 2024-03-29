/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:42:54 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/12 21:51:23 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				flag;

	flag = 0;
	i = 0;
	if (n > 0)
	{
		while (i <= (n - 1))
		{
			if (src[i] == 0)
				flag = 1;
			if (flag == 0)
				dest[i] = src[i];
			else
				dest[i] = 0;
			i++;
		}
	}
	return (dest);
}

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
