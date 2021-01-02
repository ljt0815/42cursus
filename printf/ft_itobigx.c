/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:36:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 14:37:16 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itobigx(unsigned int n)
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
					(new_n % 16) + 55 : (new_n % 16) + 48;
		new_n /= 16;
		len--;
	}
	return (result);
}
