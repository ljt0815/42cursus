/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/18 16:04:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	proc_zero(t_parse_dat *dat, char *tmp, char *result, int len)
{
	int minus;

	minus = 0;
	if (dat->width <= dat->precision)
		ft_memset(result, '0', dat->precision + 1);
	else if (dat->precision == 0)
		ft_memset(result, '0', dat->width + 1);
	else
		ft_memset(result + (dat->width - dat->precision), '0', dat->precision);
	if (tmp[0] == '-')
	{
		result[0] = '-';
		result += 1;
		tmp += 1;
		minus = 1;
	}
	if (dat->width <= dat->precision)
		ft_strncpy(result + (dat->precision - len + minus), tmp, len - minus);
	else
		ft_strncpy(result + (dat->width - len), tmp, len - minus);
}

char	*alloc_arr(t_parse_dat *dat, int len)
{
	char *result;

	if (len < dat->width)
	{
		if ((dat->width) < dat->precision)
		{
			result = malloc(dat->precision + 1);
			ft_memset(result, ' ', dat->precision + 1);
		}
		else
		{
			result = malloc(dat->width + 1);
			ft_memset(result, ' ', dat->width + 1);
		}
	}
	else
	{
		result = malloc(len + 1);
		ft_memset(result, ' ', len + 1);
	}
	return (result);
}

void	print_flag(char *result, char *tmp, int *rtn, t_parse_dat *dat)
{
	int len;
	int minus;

	minus = 0;
	if (tmp[0] == '-')
		minus = 1;
	if ((len = ft_strlen(tmp)) < dat->width)
	{
		if (dat->width <= dat->precision)
		{
			write(1, result, dat->precision + minus);
			*rtn += (dat->precision + minus);
		}
		else
		{
			write(1, result, dat->width);
			*rtn += dat->width;
		}
	}
	else
	{
		write(1, result, len);
		*rtn += len;
	}
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*tmp;
	int		len;

	tmp = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(tmp);
	if (dat->width != 0)
	{
		result = alloc_arr(dat, len);
		if (dat->flag == FLAG_ZERO)
			proc_zero(dat, tmp, result, len);
		else if (dat->flag == FLAG_MINUS)
			ft_strncpy(result, tmp, len);
		else
			ft_strncpy(result + (dat->width - len), tmp, len);
		print_flag(result, tmp, rtn, dat);
	}
	else
	{
		write(1, tmp, len);
		*rtn += len;
	}
}
