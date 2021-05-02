/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 02:34:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 02:42:39 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press3(int key, t_dat *dat, double olddirx, double oldplanex)
{
	olddirx = dat->p.dirx;
	if (key == 124)
	{
		dat->p.dirx = dat->p.dirx * cos(-dat->rotspeed) - \
					dat->p.diry * sin(-dat->rotspeed);
		dat->p.diry = olddirx * sin(-dat->rotspeed) + \
					dat->p.diry * cos(-dat->rotspeed);
		oldplanex = dat->p.planex;
		dat->p.planex = dat->p.planex * cos(-dat->rotspeed) - \
						dat->p.planey * sin(-dat->rotspeed);
		dat->p.planey = oldplanex * sin(-dat->rotspeed) + \
						dat->p.planey * cos(-dat->rotspeed);
	}
	if (key == 123)
	{
		dat->p.dirx = dat->p.dirx * cos(dat->rotspeed) - \
			dat->p.diry * sin(dat->rotspeed);
		dat->p.diry = olddirx * sin(dat->rotspeed) + \
			dat->p.diry * cos(dat->rotspeed);
		oldplanex = dat->p.planex;
		dat->p.planex = dat->p.planex * cos(dat->rotspeed) - \
						dat->p.planey * sin(dat->rotspeed);
		dat->p.planey = oldplanex * sin(dat->rotspeed) + \
						dat->p.planey * cos(dat->rotspeed);
	}
}
