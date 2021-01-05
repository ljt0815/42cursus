/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/05 20:19:26 by jitlee           ###   ########.fr       */
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
	else if (dat->flag & FLAG_ZERO && num[0] != ' ')
		ft_memset(tmp, '0', dat->read_size - ft_strlen(num));
	if ((dat->flag & FLAG_ZERO) && dat->precision == 0)
		ft_strncpy(tmp + dat->read_size - \
				ft_strlen(num) - minus, num, ft_strlen(num));
	else if (dat->precision > (int)ft_strlen(num))
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
	else
		ft_strncpy(tmp, num, ft_strlen(num));
}

void	sub_fill(char *result, char *tmp, int num_len, t_parse_dat *dat)
{
	int idx;
	int minus;

	minus = 0;
	idx = 0;
	if (tmp[0] == '-')
		minus = 1;
	if (dat->flag & FLAG_ZERO)
	{
		if (num_len <= dat->precision)
			ft_strncpy(result + dat->read_size - \
					dat->precision - minus, tmp, ft_strlen(tmp));
		else
			ft_strncpy(result + dat->read_size - num_len, tmp, ft_strlen(tmp));
	}
	else if ((int)ft_strlen(tmp) > num_len && dat->precision != 0)
	{
		if ((idx = dat->width - dat->precision - minus) > 0)
			ft_strncpy(result + (idx), tmp, ft_strlen(tmp));
		else
			ft_strncpy(result, tmp, ft_strlen(tmp));
	}
	else
		ft_strncpy(result + dat->read_size - num_len, tmp, ft_strlen(tmp));
}

void	fill_back(char *result, char *tmp, char *num, t_parse_dat *dat)
{
	int tmp_len;

	tmp_len = ft_strlen(tmp);
	ft_memset(result, ' ', dat->read_size);
	if (dat->flag & FLAG_MINUS)
		ft_strncpy(result, tmp, tmp_len);
	else if (dat->flag & FLAG_ZERO && dat->precision == 0)
		ft_strncpy(result, tmp, tmp_len);
	else
		sub_fill(result, tmp, ft_strlen(num), dat);
}

char	*alloc_arr(char *num, t_parse_dat *dat)
{
	char	*tmp;

	dat->read_size = dat->width;
	if (dat->width < (int)ft_strlen(num))
		dat->read_size = ft_strlen(num);
	if (dat->read_size <= dat->precision)
	{
		if (num[0] == '-')
			dat->read_size = dat->precision + 1;
		else
			dat->read_size = dat->precision;
	}
	tmp = malloc(dat->read_size + 1);
	if (dat->precision == 0 && num[0] == '0' \
			&& dat->dot == 1 && dat->width == 0)
		dat->read_size = 0;
	else if (dat->precision == 0 && num[0] == '0' && dat->dot == 1)
		num[0] = ' ';
	return (tmp);
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;

	if (dat->specifier == SPEC_U)
		num = ft_uitoa(va_arg(*ap, unsigned int));
	else
		num = ft_itoa(va_arg(*ap, int));
	if ((dat->flag & FLAG_ZERO) && dat->dot == 1 && dat->precision == 0)
		dat->flag -= FLAG_ZERO;
	tmp = alloc_arr(num, dat);
	ft_memset(tmp, 0, dat->read_size + 1);
	fill_front(tmp, num, dat);
	result = malloc(dat->read_size);
	fill_back(result, tmp, num, dat);
	write(1, result, dat->read_size);
	*rtn += dat->read_size;
	free(num);
	free(tmp);
	free(result);
}
