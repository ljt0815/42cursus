/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/21 12:28:06 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	proc_zero(t_parse_dat *dat, char *tmp, char *result, int len)
{
	int minus;
	int idx;

	minus = 0;
	idx = 0;
	if (dat->width <= dat->precision)
		ft_memset(result, '0', dat->precision + 1);
	else if (dat->precision == 0)
		ft_memset(result, '0', dat->width + 1);
	else
	{
		ft_memset(result + (dat->width - dat->precision), '0', dat->precision);
		idx = dat->width - dat->precision - 1;
	}
	if (tmp[0] == '-')
	{
		result[idx] = '-';
		result += 1;
		tmp += 1;
		minus = 1;
	}
	if (dat->width <= dat->precision)
		ft_strncpy(result + (dat->precision - len + minus), tmp, len - minus);
	else
		ft_strncpy(result + (dat->width - len), tmp, len - minus);
}

void	proc_minus(t_parse_dat *dat, char *tmp, char *result, int len)
{
	int minus;

	minus = 0;
	if (tmp[0] == '-')
	{
		result[0] = '-';
		result += 1;
		tmp += 1;
		minus = 1;
	}
	if (dat->precision != 0)
	{
		ft_memset(result, '0', dat->precision);
		ft_strncpy(result + (dat->precision - len + minus), tmp, len - minus);
	}
	else
		ft_strncpy(result, tmp, len - minus);
}

char	*alloc_arr(t_parse_dat *dat, int len)
{
	char	*result;
	int		size;

	if (dat->width == 0 && dat->precision != 0)
		size = dat->precision;
	else if (len < dat->width)
	{
		if ((dat->width) < dat->precision)
			size = dat->precision;
		else
			size = dat->width;
	}
	else if (dat->width < dat->precision)
		size = dat->precision;
	else
		size = len;
	result = malloc(size + 1);
	ft_memset(result, ' ', size + 1);
	return (result);
}

void	print_flag(char *result, char *tmp, int *rtn, t_parse_dat *dat)
{
	int minus;
	int size;

	minus = 0;
	if ((int)(ft_strlen(tmp)) < dat->width)
	{
		if (dat->width <= dat->precision)
		{
			size = dat->precision;
			if (tmp[0] == '-')
				minus = 1;
		}
		else
			size = dat->width;
	}
	else if (dat->width < dat->precision)
	{
		size = dat->precision;
		if (tmp[0] == '-')
			minus = 1;
	}
	else
		size = ft_strlen(tmp);
	write(1, result, size + minus);
	*rtn += (size + minus);
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*tmp;
	int		len;

	tmp = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(tmp);
	result = alloc_arr(dat, len);
	if (dat->width != 0)
	{
		if (dat->flag == FLAG_ZERO)
			proc_zero(dat, tmp, result, len);
		else if (dat->flag == FLAG_MINUS)
			proc_minus(dat, tmp, result, len);
		else
			ft_strncpy(result + (dat->width - len), tmp, len);
		print_flag(result, tmp, rtn, dat);
	}
	else
	{
		proc_else(dat, tmp, result, len);
		print_else(result, tmp, rtn, dat);
	}
	free(result);
}
