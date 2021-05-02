/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 06:25:48 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 02:44:01 by jitlee           ###   ########.fr       */
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

void	key_press2(int key, t_dat *dat)
{
	if (key == 0)
	{
		if (!dat->map.map[(int)(dat->p.x - dat->p.diry * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x -= dat->p.diry * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y - \
					dat->p.dirx * dat->movespeed)])
			dat->p.y += dat->p.dirx * dat->movespeed;
	}
	if (key == 2)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.diry * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x += dat->p.diry * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y + \
					dat->p.dirx * dat->movespeed)])
			dat->p.y -= dat->p.dirx * dat->movespeed;
	}
	key_press3(key, dat, 0, 0);
}

int		key_press(int key, t_dat *dat)
{
	if (key == 13)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.dirx * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x += dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y + \
					dat->p.diry * dat->movespeed)])
			dat->p.y += dat->p.diry * dat->movespeed;
	}
	if (key == 1)
	{
		if (!dat->map.map[(int)(dat->p.x - dat->p.dirx * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x -= dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y - \
					dat->p.diry * dat->movespeed)])
			dat->p.y -= dat->p.diry * dat->movespeed;
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
			dat->buf[y][x] = d->ccolor;
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
			dat->buf[y][x] = d->fcolor;
	}
}

void	choice_tex(t_dat *dat, t_d *d)
{
	if (d->side == 0 && d->raydirx < 0)
		d->texnum = 0;
	else if (d->side == 0 && d->raydirx >= 0)
		d->texnum = 1;
	else if (d->side == 1 && d->raydiry < 0)
		d->texnum = 2;
	else if (d->side == 1 && d->raydiry >= 0)
		d->texnum = 3;
}
