/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/25 13:22:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (dat->flag == FLAG_ZERO)
		ft_memset(tmp, '0', dat->read_size - ft_strlen(num));
	else
		ft_memset(tmp, '0', dat->precision);
	if (dat->read_size == dat->precision)
		dat->read_size += minus;
	if (dat->precision > (int)ft_strlen(num) && dat->flag == FLAG_ZERO)
		ft_strncpy(tmp + dat->read_size - \
				ft_strlen(num) - minus, num, ft_strlen(num));
	else if (dat->precision > (int)ft_strlen(num))
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
	else
		ft_strncpy(tmp, num, ft_strlen(num));
}

void	fill_back(char *result, char *tmp, char *num, t_parse_dat *dat)
{
	int tmp_len;
	int num_len;
	int minus;
	int	idx;

	minus = 0;
	idx = 0;
	num_len = ft_strlen(num);
	if (tmp[0] == '-')
		minus = 1;
	if (dat->flag == FLAG_ZERO)
		idx = dat->read_size - num_len;
	if ((tmp_len = ft_strlen(tmp)) > num_len + idx)
	{
		if ((idx = dat->width - dat->precision - minus) > 0)
			ft_strncpy(result + (idx), tmp, tmp_len);
		else
			ft_strncpy(result, tmp, tmp_len);
		return ;
	}
	if (dat->flag == FLAG_MINUS)
		ft_strncpy(result, tmp, tmp_len);
	else
		ft_strncpy(result + dat->read_size - num_len, tmp, tmp_len);
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
