/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 06:25:48 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/30 07:40:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_draw(t_dat *dat)
{
	int	y;
	int x;

	y = -1;
	while (++y < dat->r.y)
	{
		x = -1;
		while (++x < dat->r.x)
			dat->img.data[y * dat->r.x + x] = dat->buf[y][x];
	}
	mlx_put_image_to_window(dat->mlx, dat->win, dat->img.img, 0, 0);
}

int		key_press(int key, t_dat *dat)
{
	if (key == 13)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.dirx * dat->movespeed)][(int)(dat->p.y)])
					dat->p.x += dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y + dat->p.diry * dat->movespeed)])
					dat->p.y += dat->p.diry * dat->movespeed;
	}
	if (key == 2)
	{
		double oldDirX = dat->p.dirx;
		dat->p.dirx = dat->p.dirx * cos(-dat->rotspeed) - dat->p.diry * sin(-dat->rotspeed);
		dat->p.diry = oldDirX * sin(-dat->rotspeed) + dat->p.diry * cos(-dat->rotspeed);
		double oldPlaneX = dat->p.planex;
		dat->p.planex = dat->p.planex * cos(-dat->rotspeed) - dat->p.planey * sin(-dat->rotspeed);
		dat->p.planey = oldPlaneX * sin(-dat->rotspeed) + dat->p.planey * cos(-dat->rotspeed);
	}
	if (key == 53)
		exit(0);
	return (0);
}
