/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/14 17:15:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	proc_zero(t_parse_dat *dat, char *tmp, char *result, int len)
{
	int flag;

	flag = 0;
	if (dat->width < dat->precision)
		flag = 1; 
	if (flag == 1)
		ft_memset(result, '0', dat->precision + 1);
	else if (dat->precision == 0)
		ft_memset(result, '0', dat->width + 1);
	else
		ft_memset(result + (dat->width - dat->precision), '0', dat->precision);
	if (tmp[0] == '-')
	{
		result[0] = '-';
		tmp += 1;
		len -= 1;
	}
	if (flag == 1)
		ft_strncpy(result + (dat->precision - len), tmp, len);
	else
		ft_strncpy(result + (dat->width - len), tmp, len);
}

char	*alloc_arr(int flag)
{
	char *result;

	result = malloc(flag + 1);
	ft_memset(result, ' ', flag);
	return (result);
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*tmp;
	int		len;
	int		flag;

	tmp = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(tmp);
	if ((flag = dat->width) < dat->precision)
		flag = dat->precision;
	if (dat->width != 0)
	{
		result = alloc_arr(flag);
		if (dat->flag == FLAG_ZERO)
			proc_zero(dat, tmp, result, len);
		else if (dat->flag == FLAG_MINUS)
			ft_strncpy(result, tmp, len);
		else
			ft_strncpy(result + (dat->width - len), tmp, len);
		write(1, result, flag);
		*rtn += flag;
	}
	else
	{
		write(1, tmp, len);
		*rtn += len;
	}
}
