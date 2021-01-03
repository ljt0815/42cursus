/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:08:28 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/03 18:50:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char *s, t_parse_dat *dat)
{
	if (*s == '-')
	{
		dat->flag |= FLAG_MINUS;
		return (1);
	}
	else if (*s == '0')
	{
		dat->flag |= FLAG_ZERO;
		return (1);
	}
	return (0);
}

void	set_width(char *s, t_parse_dat *dat, int *i)
{
	if (*s >= '0' && *s <= '9')
	{
		dat->width = dat->width * 10 + (*s - '0');
		*i = *i + 1;
	}
}

void	is_length_sub(char *s, t_parse_dat *dat)
{
	if (*s == 'j')
		dat->length = LENGTH_J;
	else if (*s == 'z')
		dat->length = LENGTH_Z;
	else if (*s == 't')
		dat->length = LENGTH_T;
	else if (*s == 'L')
		dat->length = LENGTH_BIGL;
}

void	is_length(char *s, t_parse_dat *dat, int *i)
{
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
		{
			dat->length = LENGTH_HH;
			*i += 1;
		}
		else
			dat->length = LENGTH_H;
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l')
		{
			dat->length = LENGTH_LL;
			*i += 1;
		}
		else
			dat->length = LENGTH_L;
	}
	is_length_sub(s, dat);
	if (dat->length != 0)
		*i += 1;
}

void	is_specifier(char *s, t_parse_dat *dat, int *i)
{
	if (*s == 'c')
		dat->specifier = SPEC_C;
	else if (*s == 's')
		dat->specifier = SPEC_S;
	else if (*s == 'p')
		dat->specifier = SPEC_P;
	else if (*s == 'd')
		dat->specifier = SPEC_D;
	else if (*s == 'i')
		dat->specifier = SPEC_I;
	else if (*s == 'u')
		dat->specifier = SPEC_U;
	else if (*s == 'x')
		dat->specifier = SPEC_X;
	else if (*s == 'X')
		dat->specifier = SPEC_BIGX;
	else if (*s == '%')
		dat->specifier = SPEC_PER;
	if (dat->specifier != 0)
		*i += 1;
}
