/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/24 16:28:33 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*alloc_arr(t_parse_dat *dat, int len, int *read_size)
{
	char	*result;

	*read_size = dat->width;
	if (dat->width < dat->precision)
		*read_size = dat->precision;
	if (len > *read_size)
		*read_size = len;
	result = malloc(*read_size + 1);
	ft_memset(result, 0, *read_size + 1);
	return (result);
}

void	fill_front(char *tmp, char *num, int *read_size, t_parse_dat *dat)
{
	int idx;
	
	idx = *read_size;
	if (num[0] == '-')
	{
		tmp[0] = '-';
		tmp++;
		num++;
		(*read_size)++;
		idx--;
		write(1, "11\n", 3);
	}
	ft_memset(tmp, '0', dat->precision);
	if (dat->precision > (int)ft_strlen(num))
	{
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
		write(1, "12\n", 3);
	}
	else
	{
		ft_strncpy(tmp, num, ft_strlen(num));
		write(1, "13\n", 3);
	}
}

void	fill_back(char *result, char *tmp, int read_size, t_parse_dat *dat)
{
	int tmp_len;
	int minus;
	int	idx;

	minus = 0;
	if (tmp[0] == '-')
		minus = 1;
	if ((tmp_len = ft_strlen(tmp)) < read_size)
	{
		if ((idx = dat->width - dat->precision - minus) > 0)
			ft_strncpy(result + (idx), tmp, tmp_len);
		else
			ft_strncpy(result + (read_size - tmp_len - minus), tmp, tmp_len);
		write(1, "21\n", 3);
	}
	else
	{
		ft_strncpy(result, tmp, tmp_len);
		write(1, "22\n", 3);
	}
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;
	int		read_size;

	num = ft_itoa(va_arg(*ap, int));
	tmp = alloc_arr(dat, ft_strlen(num), &read_size);
	fill_front(tmp, num, &read_size, dat);
	result = malloc(read_size);
	ft_memset(result, ' ', read_size);
	fill_back(result, tmp, read_size, dat);
	write(1, result, read_size - 1);
	*rtn += 0;
	free(result);
}
