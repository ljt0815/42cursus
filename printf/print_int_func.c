/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:15:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/19 16:19:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	proc_else(t_parse_dat *dat, char *tmp, char *result, int len)
{
	if (tmp[0] == '-' && dat->precision > len)
		ft_memset(tmp + 1, '0', dat->precision - len);
	else if (tmp[0] != '-' && dat->precision > len)
		ft_memset(tmp, '0', dat->precision - len - 1);
}
