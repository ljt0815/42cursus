/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:19:16 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 17:19:51 by jitlee           ###   ########.fr       */
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

int		parse_str(char *s, va_list *ap, t_parse_dat *dat, int *rtn)
{
	int	i;

	i = 0;
	while (ft_isflag(&s[i], dat))
		i++;
	while (ft_isdigit(s[i]))
		set_width(&s[i], dat, &i);
	if (s[i] == '.')
		set_precision(&s[++i], dat, &i);
	is_length(&s[i], dat, &i);
	is_specifier(&s[i], dat, &i);
	print_dat(dat, ap, rtn);
	return (i);
}
