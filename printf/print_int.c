/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/27 01:51:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	fill_front(char *tmp, char *num, t_parse_dat *dat)
{
	int minus;

	minus = 0;
	if (num[0] == '-')
	{
		tmp[0] = '-';
		tmp++;
		num++;
		minus = 1;
	}
	if (dat->precision != 0)
		ft_memset(tmp, '0', dat->precision);
	else if (dat->flag == FLAG_ZERO)
		ft_memset(tmp, '0', dat->read_size - ft_strlen(num));
	else
		ft_memset(tmp, ' ', dat->read_size - minus);
	if (dat->read_size == dat->precision)
		dat->read_size += minus;
	if (dat->flag == FLAG_ZERO && dat->precision == 0)
		ft_strncpy(tmp + dat->read_size - ft_strlen(num) - minus, num, ft_strlen(num));
	else if (dat->precision > (int)ft_strlen(num))
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
	else
		ft_strncpy(tmp, num, ft_strlen(num));
}

void	sub_fill(char *result, char *tmp, int num_len, t_parse_dat *dat)
{
	int idx;
	int minus;
	int tmp_len;

	tmp_len = ft_strlen(tmp);
	minus = 0;
	idx = 0;
	if (tmp[0] == '-')
		minus = 1;
	if (dat->flag == FLAG_ZERO)
		if ((idx = dat->read_size - num_len) < 0)
			idx = 0;
	if (dat->precision != 0 && dat->flag == FLAG_ZERO)
		ft_strncpy(result + dat->read_size - dat->precision - minus, tmp, tmp_len);
	else if (tmp_len > num_len + idx && dat->precision != 0)
	{
		if ((idx = dat->width - dat->precision - minus) > 0)
			ft_strncpy(result + (idx), tmp, tmp_len);
		else
			ft_strncpy(result, tmp, tmp_len);
	}
	else
		ft_strncpy(result + dat->read_size - num_len, tmp, tmp_len);
}

void	fill_back(char *result, char *tmp, char *num, t_parse_dat *dat)
{
	int tmp_len;
	int num_len;

	num_len = ft_strlen(num);
	tmp_len = ft_strlen(tmp);
	if (dat->flag == FLAG_ZERO && dat->precision == 0)
		ft_strncpy(result, tmp, tmp_len);
	else if (dat->flag == FLAG_MINUS)
		ft_strncpy(result, tmp, tmp_len);
	else
		sub_fill(result, tmp, num_len, dat);
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;

	num = ft_itoa(va_arg(*ap, int));
	dat->read_size = dat->width;
	if (dat->width < dat->precision)
		dat->read_size = dat->precision;
	if ((int)ft_strlen(num) > dat->read_size)
		dat->read_size = ft_strlen(num);
	tmp = malloc(dat->read_size + 1);
	ft_memset(tmp, 0, dat->read_size + 1);
	fill_front(tmp, num, dat);
	result = malloc(dat->read_size);
	ft_memset(result, ' ', dat->read_size);
	fill_back(result, tmp, num, dat);
	write(1, result, dat->read_size);
	*rtn += dat->read_size;
	free(result);
}
