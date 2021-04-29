/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk_func3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:54:34 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/30 01:24:02 by jitlee           ###   ########.fr       */
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

void	player_dir2(t_dat *dat, char news)
{
	if (news == 'W')
	{
		dat->p.dirx = -1.0;
		dat->p.diry = 0.0;
		dat->p.planex = 0.0;
		dat->p.planey = 0.66;
	}
	else if (news == 'E')
	{
		dat->p.dirx = -1.0;
		dat->p.diry = 0.0;
		dat->p.planex = 0.0;
		dat->p.planey = 0.66;
	}
}

void	player_dir(t_dat *dat, char news)
{
	if (news == 'N')
	{
		dat->p.dirx = -1.0;
		dat->p.diry = 0.0;
		dat->p.planex = 0.0;
		dat->p.planey = 0.66;
	}
	else if (news == 'S')
	{
		dat->p.dirx = -1.0;
		dat->p.diry = 0.0;
		dat->p.planex = 0.0;
		dat->p.planey = 0.66;
	}
	else
		player_dir2(dat, news);
}
