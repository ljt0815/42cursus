/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:19:16 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/19 00:23:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char *s)
{
	if (s[i] == '-')
	{
		dat->flag = FLAG_MINUS;
		i++;
	}
	else if (s[i] == '0')
	{
		dat->flag = FLAG_ZERO;
		i++;
	}
}

int	is_width(

int	parse_str(char *s, va_list *ap, t_parse_dat *dat)
{
	int i;

	ap += 0;
	i = 0;
	if (s[i] == '%')
	{
		write(1 , "%", 1);
		return (1);
	}
	if (is_flag(s[i]))
		i++;
	if (is_width(s[i]))
		i++;

	return (0);
}
