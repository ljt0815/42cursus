/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:47:47 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/08 16:40:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ch(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	int		i;

	i = 0;
	if (dat->width != 0)
	{
		result = malloc(dat->width);
		while (i < dat->width)
		{
			result[i] = ' ';
			i++;
		}
		result[dat->width - 1] = va_arg(*ap, int);
		*rtn += dat->width;
		write(1, result, dat->width);
	}
	else
	{
		result = malloc(1);
		result[0] = va_arg(*ap, int);
		*rtn += 1;
		write(1, result, 1);
	}
}
