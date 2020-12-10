/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:31:42 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 20:01:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_adr(void *addr)
{
	unsigned long	tmp;
	char			full_addr[16];
	int				i;

	tmp = (unsigned long)addr;
	i = 0;
	while (i < 16)
	{
		full_addr[15 - i] = (tmp % 16) >= 10 ? \
							(tmp % 16) + 87 : (tmp % 16) + 48;
		tmp = tmp / 16;
		i++;
	}
	write(1, full_addr, 16);
	write(1, ": ", 2);
}

void	print_adr(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char		*result;
	void		*tmp;
	long long	adr;

	adr = va_arg(*ap, void *);
}
