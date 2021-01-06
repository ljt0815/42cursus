/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:31:42 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/06 20:41:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_convert(long long tmp, int *rtn, int len)
{
	char	full_addr[12];
	char	*idx;
	int		i;

	i = 0;
	while (i < 12)
	{
		full_addr[11 - i] = (tmp % 16) >= 10 ? \
							(tmp % 16) + 87 : (tmp % 16) + 48;
		tmp = tmp / 16;
		i++;
	}
	i = 0;
	while (full_addr[i] == '0')
		i++;
	write(1, "0x", 2);
	write(1, full_addr + i, len);
	*rtn += 2 + len;
}

void	null_proc(t_parse_dat *dat, int *rtn)
{
	int i;
	int len;

	if (dat->dot == 1 && dat->precision == 0)
		len = 2;
	else
		len = 3;
	i = len;
	if (dat->flag == FLAG_MINUS)
		write(1, "0x0", len);
	while (i < dat->width)
	{
		write(1, " ", 1);
		i++;
		*rtn += 1;
	}
	if (dat->flag != FLAG_MINUS)
		write(1, "0x0", len);
	*rtn += len;
}

void	print_adr(t_parse_dat *dat, va_list *ap, int *rtn)
{
	int			i;
	int			len;
	long long	tmp;

	i = 0;
	tmp = (long long)va_arg(*ap, void *);
	len = hex_len(tmp) + 2;
	if (tmp == 0)
		null_proc(dat, rtn);
	else if (dat->width != 0 && (len > dat->width))
	{
		if (dat->flag == FLAG_MINUS)
			hex_convert(tmp, rtn, len);
		while (i < dat->width - len)
		{
			write(1, " ", 1);
			i++;
			*rtn += 1;
		}
		if (dat->flag != FLAG_MINUS)
			hex_convert(tmp, rtn, len);
	}
	else
		hex_convert(tmp, rtn, len);
}
