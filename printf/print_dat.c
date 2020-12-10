/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:11:28 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 19:36:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_dat(t_parse_dat *dat, va_list *ap, int *rtn)
{
	if (dat->specifier == 0)
		return ;
	else if (dat->specifier == SPECIFIER_C)
		print_ch(dat, ap, rtn);
	else if (dat->specifier == SPECIFIER_S)
		print_str(dat, ap, rtn);
	else if (dat->specifier == SPECIFIER_P)
		print_adr(dat, ap, rtn);
	/*else if (dat->specifier == SPECIFIER_D || dat->specifier == SPECIFIER_I)
		print_int(dat, ap);
	else if (dat->specifier == SPECIFIER_U)
		print_uint(dat, ap);
	else if (dat->specifier == SPECIFIER_X)
		print_lhex(dat, ap);
	else if (dat->specifier == SPECIFIER_BIGX)
		print_uhex(dat, ap);
	else if (dat->specifier == SPECIFIER_PER)
		print_per(dat, ap);
	else
		print_err();*/
}
