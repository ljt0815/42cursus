/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:55:54 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/01 14:44:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	if ((tmp = va_arg(*ap, char *)) == 0)
		tmp = "(null)";
	if ((dat->precision == 0 && dat->dot == 0) \
				|| dat->precision > (int)ft_strlen(tmp))
		len = ft_strlen(tmp);
	else
		len = dat->precision;
	if (dat->flag & FLAG_MINUS)
		write(1, tmp, len);
	while (++i < dat->width - len)
	{
		write(1, " ", 1);
		*rtn += 1;
	}
	if ((dat->flag & FLAG_MINUS) == 0)
		write(1, tmp, len);
	*rtn += len;
}
