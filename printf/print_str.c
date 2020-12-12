/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:55:54 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/12 21:51:52 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*tmp;
	int		len;

	tmp = va_arg(*ap, char *);
	if (dat->precision == 0)
		len = ft_strlen(tmp);
	else
		len = dat->precision;
	if (dat->width != 0 && len < dat->width)
	{
		result = malloc(dat->width + 1);
		ft_memset(result, ' ', dat->width + 1);
		if (dat->flag == FLAG_MINUS)
			ft_strncpy(result, tmp, len);
		else
			ft_strlcpy(result + (dat->width - len), tmp, len + 1);
		write(1, result, dat->width);
		*rtn += dat->width;
	}
	else
	{
		write(1, tmp, len);
		*rtn += len;
	}
}
