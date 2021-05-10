/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:44 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/10 14:52:15 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_update(t_dat *dat, double olddirx, double oldplanex, int x)
{
	if (x > dat->f_sw / 2)
	{
		dat->p.dirx = dat->p.dirx * cos(-dat->rotspeed) - \
					dat->p.diry * sin(-dat->rotspeed);
		dat->p.diry = olddirx * sin(-dat->rotspeed) + \
					dat->p.diry * cos(-dat->rotspeed);
		dat->p.planex = dat->p.planex * cos(-dat->rotspeed) - \
						dat->p.planey * sin(-dat->rotspeed);
		dat->p.planey = oldplanex * sin(-dat->rotspeed) + \
						dat->p.planey * cos(-dat->rotspeed);
	}
	else if (x < dat->f_sw / 2)
	{
		dat->p.dirx = dat->p.dirx * cos(dat->rotspeed) - \
			dat->p.diry * sin(dat->rotspeed);
		dat->p.diry = olddirx * sin(dat->rotspeed) + \
			dat->p.diry * cos(dat->rotspeed);
		dat->p.planex = dat->p.planex * cos(dat->rotspeed) - \
						dat->p.planey * sin(dat->rotspeed);
		dat->p.planey = oldplanex * sin(dat->rotspeed) + \
						dat->p.planey * cos(dat->rotspeed);
	}
}

int		move_mouse(t_dat *dat)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(dat->win, &x, &y);
	mouse_update(dat, dat->p.dirx, dat->p.planex, x);
	mlx_mouse_move(dat->win, dat->f_sw / 2, dat->f_sh / 4);
	mlx_mouse_hide();
	return (0);
}
