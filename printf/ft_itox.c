/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:58:09 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 14:33:54 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_len(long long n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itox(unsigned int n)
{
	char		*result;
	int			len;
	int			flag;
	long long	new_n;

	new_n = (long long)n;
	flag = 0;
	len = hex_len(new_n);
	if ((result = (char *)malloc(len + 1)) == 0)
		return (0);
	if (new_n < 0)
	{
		result[0] = '-';
		new_n *= -1;
		flag = 1;
	}
	result[len--] = 0;
	while (len >= flag)
	{
		result[len] = (new_n % 16) >= 10 ? \
					(new_n % 16) + 87 : (new_n % 16) + 48;
		new_n /= 16;
		len--;
	}
	return (result);
}
