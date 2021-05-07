/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:11:23 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/07 23:32:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		num_len(long long n)
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
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	int			flag;
	long long	new_n;

	new_n = (long long)n;
	flag = 0;
	len = num_len(new_n);
	result = (char *)malloc(len + 1);
	if (result == 0)
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
		result[len] = (new_n % 10) + 48;
		new_n /= 10;
		len--;
	}
	return (result);
}
