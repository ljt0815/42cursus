/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:28:58 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/06 19:03:19 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*num;
	char	*tmp;

	if (dat->specifier == SPEC_BIGX)
		num = ft_itobigx(va_arg(*ap, unsigned int));
	else
		num = ft_itox(va_arg(*ap, unsigned int));
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
	free(result);
	free(tmp);
}
