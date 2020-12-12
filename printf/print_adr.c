/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:31:42 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/13 00:50:11 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_convert(void *addr)
{
	unsigned long	tmp;
	char			full_addr[9];
	int				i;

	tmp = (unsigned long)addr;
	i = 0;
	while (i < 9)
	{
		full_addr[8 - i] = (tmp % 16) >= 10 ? \
							(tmp % 16) + 87 : (tmp % 16) + 48;
		tmp = tmp / 16;
		i++;
	}
	write(1, "0x", 2);
	write(1, full_addr, 9);
}

void	print_adr(t_parse_dat *dat, va_list *ap, int *rtn)
{
	int i;

	i = 11;
	if (dat->width != 0 && dat->width > 11)
	{
		if (dat->flag == FLAG_MINUS)
			hex_convert(va_arg(*ap, void *));
		while (i < dat->width)
		{
			write(1, " ", 1);
			i++;
			*rtn += 1;
		}
		if (dat->flag == 0)
			hex_convert(va_arg(*ap, void *));
	}
	else
		hex_convert(va_arg(*ap, void *));
	*rtn += 11;
}
