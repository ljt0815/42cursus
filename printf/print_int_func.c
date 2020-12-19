/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:15:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/19 17:15:03 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	proc_else(t_parse_dat *dat, char *tmp, char *result, int len)
{
	int minus;

	minus = 0;
	if (dat->precision > len)
	{
		if (tmp[0] == '-')
		{
			result[0] = '-';
			result += 1;
			tmp += 1;
			minus = 1;
		}
		ft_memset(result, '0', (dat->precision + minus) - len);
		ft_strncpy(result + (dat->precision - len + minus), tmp, len - minus);
	}
	else
		ft_strncpy(result, tmp, len);
}

void	print_else(char *result, char *tmp, int *rtn, t_parse_dat *dat)
{
	int len;
	int minus;

	minus = 0;
	if (tmp[0] == '-')
		minus = 1;
	len = ft_strlen(tmp);
	if (dat->precision > len)
	{
		write(1, result, dat->precision + minus);
		*rtn += dat->precision + minus;
	}
	else
	{
		write(1, result, len);
		*rtn += len;
	}
}
