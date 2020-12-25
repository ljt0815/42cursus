/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/25 11:14:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*alloc_arr(t_parse_dat *dat, int len)
{
	char	*result;

	dat->read_size = dat->width;
	if (dat->width < dat->precision)
		dat->read_size = dat->precision;
	if (len > dat->read_size)
		dat->read_size = len;
	result = malloc(dat->read_size + 1);
	ft_memset(result, 0, dat->read_size + 1);
	return (result);
}

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
		write(1, "11\n", 3);
	}
	ft_memset(tmp, '0', dat->precision);
	if (dat->precision > (int)ft_strlen(num))
	{
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
		dat->read_size += minus;
		write(1, "12\n", 3);
	}
	else
	{
		ft_strncpy(tmp, num, ft_strlen(num));
		write(1, "13\n", 3);
	}
}

void	fill_back(char *result, char *tmp, char *num, t_parse_dat *dat)
{
	int tmp_len;
	int minus;
	int	idx;
	int num_len;

	minus = 0;
	if (tmp[0] == '-')
		minus = 1;
	if ((tmp_len = ft_strlen(tmp)) > (num_len = ft_strlen(num)))
	{
		if ((idx = dat->width - dat->precision - minus) > 0)
			ft_strncpy(result + (idx), tmp, tmp_len);
		else
		{
			ft_strncpy(result, tmp, tmp_len);
			write(1, "20\n", 3);
		}
		write(1, "21\n", 3);
	}
	else
	{
		ft_strncpy(result + dat->read_size - num_len, tmp, tmp_len);
		write(1, "22\n", 3);
	}
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;

	num = ft_itoa(va_arg(*ap, int));
	tmp = alloc_arr(dat, ft_strlen(num));
	fill_front(tmp, num, dat);
	result = malloc(dat->read_size);
	ft_memset(result, ' ', dat->read_size);
	fill_back(result, tmp, num, dat);
	write(1, result, dat->read_size);
	*rtn += 0;
	free(result);
}
