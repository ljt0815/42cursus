/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk_func3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:54:34 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/23 03:57:39 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	isdigit_chk(char ch, char flag)
{
	if (ft_isdigit(ch) == 0)
	{
		if (flag == 'f')
			err_msg("Identifier \"F\" Exception");
		if (flag == 'c')
			err_msg("Identifier \"C\" Exception");
	}
}
