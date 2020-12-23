/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/23 14:00:34 by jitlee           ###   ########.fr       */
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
	ft_memset(result, ' ', *read_size + 1);
	return (result);
}

void	fill_front(char *tmp, char *num, int *read_size)
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
	}
	ft_memset(tmp, '0', idx);
	if (dat->precision > ft_strlen(num))
		ft_strncpy(tmp + dat->precision - ft_strlen(num), num, ft_strlen(num));
	else
		ft_strncpy(tmp, num, ft_strlen(num));
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;
	int		read_size;

	num = ft_itoa(va_arg(*ap, int));
	result = alloc_arr(dat, ft_strlen(num), &read_size);
	fill_front(result, tmp, num, &read_size);
	fill_back(
	free(result);
}
