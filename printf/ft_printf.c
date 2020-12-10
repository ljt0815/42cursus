/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:56:26 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 17:29:45 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int			i;
	int			idx;
	int			rtn;
	va_list		ap;
	t_parse_dat	dat;

	ft_bzero(&dat, sizeof(t_parse_dat));
	va_start(ap, s);
	i = -1;
	rtn = 0;
	while (s[++i] != 0)
	{
		if (s[i] == '%')
		{
			idx = parse_str((char *)&s[i + 1], &ap, &dat, &rtn);
			i += idx;
		}
		else
		{
			write(1, &s[i], 1);
			rtn++;
		}
	}
	va_end(ap);
	return (rtn);
}
