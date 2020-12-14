/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:34 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/14 15:16:43 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_zero(t_parse_dat *dat, char *tmp, char *result, int len)
{
	if (tmp == 0)
		return ;
	ft_memset(result, '0', dat->width);
	if (tmp[0] == '-')
	{
		result[0] = '-';
		tmp += 1;
		len -= 1;
	}
	ft_strncpy(result + (dat->width - len), tmp, len);
}

void	print_int(t_parse_dat *dat, va_list *ap, int *rtn)
{
	char	*result;
	char	*tmp;
	int		len;

	tmp = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(tmp);
	if (dat->width != 0)
	{
		result = malloc(dat->width + 1);
		ft_memset(result, ' ', dat->width);
		if (dat->flag == FLAG_ZERO)
			proc_zero(dat, tmp, result, len);
		else if (dat->flag == FLAG_MINUS)
			ft_strncpy(result, tmp, len);
		else
			ft_strncpy(result + (dat->width - len), tmp, len);
		write(1, result, dat->width);
		*rtn += dat->width;
	}
	else
	{
		write(1, tmp, len);
		*rtn += len;
	}
}
