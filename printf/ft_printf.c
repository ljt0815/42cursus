/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:56:26 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/19 00:25:07 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list		ap;
	int			idx;
	t_parse_dat	dat;

	ft_bzero(&dat, sizeof(t_parse_dat));
	va_start(ap, s);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			idx = parse_str((char *)&s[i + 1], &ap, &dat);
			i += idx;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}