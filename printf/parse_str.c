/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:19:16 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/19 05:30:53 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char *s, t_parse_dat *dat)
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
	else if (*s == '+')
	{
		dat->flag |= FLAG_PLUS;
		return (1);
	}
	else if (*s == ' ')
	{
		dat->flag |= FLAG_BLANK;
		return (1);
	}
	return (0);
}

int	set_width(char *s, t_parse_dat *dat, int *i)
{
	if (*s >= '0' && *s <= '9')
		dat->width = dat->width * 10 + (*s - '0');
	*i = *i + 1;
}

int	parse_str(char *s, va_list *ap, t_parse_dat *dat)
{
	int	i;
	int	idx;

	ap += 0;//
	i = 0;
	if (ft_isflag(&s[i], dat))
		i++;
	while (ft_isdigit(s[i]))
		set_width(&s[i], dat, &i);
	return (0);
}
