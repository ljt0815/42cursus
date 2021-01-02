/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:47:24 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 15:54:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_blank(t_parse_dat *dat, int *rtn, char *c)
{
	int i;

	i = 1;
	while (i < dat->width)
	{
		write(1, c, 1);
		i++;
		*rtn += 1;
	}
}

void	print_per(t_parse_dat *dat, int *rtn)
{
	if (dat->flag & FLAG_MINUS)
		write(1, "%", 1);
	if (dat->flag & FLAG_MINUS)
		print_blank(dat, rtn, " ");
	else if (dat->flag & FLAG_ZERO)
		print_blank(dat, rtn, "0");
	else
		print_blank(dat, rtn, " ");
	if (!(dat->flag & FLAG_MINUS))
		write(1, "%", 1);
	*rtn += 1;
}
