/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:31:42 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 18:28:24 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_convert(unsigned long tmp, int *rtn)
{
	char	*full_addr;
	int		i;
	int		addr_len;

	i = 0;
	addr_len = hex_len((long long)tmp);
	full_addr = malloc(addr_len);
	while (i < addr_len)
	{
		full_addr[addr_len - i] = (tmp % 16) >= 10 ? \
							(tmp % 16) + 87 : (tmp % 16) + 48;
		tmp = tmp / 16;
		i++;
	}
	write(1, "0x", 2);
	write(1, full_addr, addr_len);
	*rtn += addr_len;
}

void	null_proc(t_parse_dat *dat, int *rtn)
{
	int i;

	i = 3;
	if (dat->flag == FLAG_MINUS)
		write(1, "0x0", 3);
	while (i < dat->width)
	{
		write(1, " ", 1);
		i++;
		*rtn += 1;
	}
	if (dat->flag != FLAG_MINUS)
		write(1, "0x0", 3);
	*rtn += 3;
}

void	print_adr(t_parse_dat *dat, va_list *ap, int *rtn)
{
	int				i;
	unsigned long	tmp;

	i = 11;
	tmp = (unsigned long)va_arg(*ap, void *);
	if (tmp == 0)
		null_proc(dat, rtn);
	else if (dat->width != 0 && (dat->width > 11))
	{
		if (dat->flag == FLAG_MINUS)
			hex_convert(tmp, rtn);
		while (i < dat->width)
		{
			write(1, " ", 1);
			i++;
			*rtn += 1;
		}
		if (dat->flag == 0)
			hex_convert(tmp, rtn);
	}
	else
		hex_convert(tmp, rtn);
	*rtn += 11;
}
