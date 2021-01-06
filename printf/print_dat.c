/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:28 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/07 00:05:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_dat(t_parse_dat *dat, va_list *ap, int *rtn)
{
	if (dat->specifier == 0)
		return ;
	else if (dat->specifier == SPEC_C)
		print_ch(dat, ap, rtn);
	else if (dat->specifier == SPEC_S)
		print_str(dat, ap, rtn);
	else if (dat->specifier == SPEC_P)
		print_adr(dat, ap, rtn);
	else if (dat->specifier == SPEC_X || dat->specifier == SPEC_BIGX)
		print_hex(dat, ap, rtn);
	else if (dat->specifier == SPEC_PER)
		print_per(dat, rtn);
	else
		print_int(dat, ap, rtn);
}
