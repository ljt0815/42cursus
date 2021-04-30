/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 06:25:48 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/30 12:02:25 by jitlee           ###   ########.fr       */
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
		{
			if (dat->buf[y][x] != 0)
				dat->img.data[y * dat->r.x + x] = dat->buf[y][x];
			else
			{
				if (y > dat->r.y / 2)
					dat->img.data[y * dat->r.x + x] = 0xeeeeee;
				else
					dat->img.data[y * dat->r.x + x] = 0x111111;
			}
		}
	}
	mlx_put_image_to_window(dat->mlx, dat->win, dat->img.img, 0, 0);
}

void	key_press2(int key, t_dat *dat)
{
	double olddirx;
	double oldplanex;

	if (key == 124)
	{
		olddirx = dat->p.dirx;
		dat->p.dirx = dat->p.dirx * cos(-dat->rotspeed) - dat->p.diry * sin(-dat->rotspeed);
		dat->p.diry = olddirx * sin(-dat->rotspeed) + dat->p.diry * cos(-dat->rotspeed);
		oldplanex = dat->p.planex;
		dat->p.planex = dat->p.planex * cos(-dat->rotspeed) - dat->p.planey * sin(-dat->rotspeed);
		dat->p.planey = oldplanex * sin(-dat->rotspeed) + dat->p.planey * cos(-dat->rotspeed);
	}
	if (key == 123)
	{
		olddirx = dat->p.dirx;
		dat->p.dirx = dat->p.dirx * cos(dat->rotspeed) - dat->p.diry * sin(dat->rotspeed);
		dat->p.diry = olddirx * sin(dat->rotspeed) + dat->p.diry * cos(dat->rotspeed);
		oldplanex = dat->p.planex;
		dat->p.planex = dat->p.planex * cos(dat->rotspeed) - dat->p.planey * sin(dat->rotspeed);
		dat->p.planey = oldplanex * sin(dat->rotspeed) + dat->p.planey * cos(dat->rotspeed);
	}
}

int		key_press(int key, t_dat *dat)
{
	printf("key : %d\n", key);
	if (key == 13)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.dirx * dat->movespeed)][(int)(dat->p.y)])
					dat->p.x += dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y + dat->p.diry * dat->movespeed)])
					dat->p.y += dat->p.diry * dat->movespeed;
	}
	if (key == 53)
		exit(0);
	key_press2(key, dat);
	return (0);
}

void	input_buf(t_dat *dat, t_d *d, int x)
{
	int y;

	y = -1;
	while (++y < dat->r.y)
	{
		if (y < d->drawstart)
			dat->buf[y][x] = 0xeeeeee;
		else if (y < d->drawend)
		{
			d->texy = (int)d->texpos & (64 - 1);
			d->texpos += d->step;
			d->color = dat->texture[d->texnum][64 * d->texy + d->texx];
			if (d->side == 1)
				d->color = (d->color >> 1) & 8355711;
			dat->buf[y][x] = d->color;
		}
		else
			dat->buf[y][x] = 0x111111;
	}
	
}
