/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:19:16 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/19 00:32:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char *s, t_parse_dat *dat)
{
	if (*s == '-')
	{
		dat->flag = FLAG_MINUS;
		return (1);
	}
	else if (*s == '0')
	{
		dat->flag = FLAG_ZERO;
		return (1);
	}
	return (0);
}

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
	if (is_flag(&s[i], dat))
		i++;

	return (0);
}
