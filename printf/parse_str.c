/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:19:16 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/07 00:06:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_precision(char *s, t_parse_dat *dat, int *i)
{
	while (ft_isdigit(*s))
	{
		dat->precision = (dat->precision * 10) + (*s - '0');
		*i += 1;
		s++;
	}
}

int		starwidth(char c, va_list *ap, t_parse_dat *dat, int *i)
{
	if (c == '*')
	{
		dat->width = va_arg(*ap, int);
		if (dat->width < 0)
		{
			dat->flag = FLAG_MINUS;
			dat->width *= -1;
		}
		*i += 1;
		return (1);
	}
	return (0);
}

int		starprecision(char c, va_list *ap, t_parse_dat *dat, int *i)
{
	dat->dot = 1;
	if (c == '*')
	{
		dat->precision = va_arg(*ap, int);
		if (dat->precision < 0)
		{
			dat->dot = 0;
			dat->precision = 0;
		}
		*i += 1;
		return (1);
	}
	return (0);
}

int		parse_str(char *s, va_list *ap, t_parse_dat *dat, int *rtn)
{
	int	i;

	i = 0;
	while (ft_isflag(&s[i], dat))
		i++;
	if (!starwidth(s[i], ap, dat, &i))
		while (ft_isdigit(s[i]))
			set_width(&s[i], dat, &i);
	if (s[i] == '.')
		if (!starprecision(s[++i], ap, dat, &i))
			set_precision(&s[i], dat, &i);
	is_length(&s[i], dat, &i);
	is_specifier(&s[i], dat, &i);
	print_dat(dat, ap, rtn);
	return (i);
}
