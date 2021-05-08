/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 06:25:48 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/08 16:02:57 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_draw(t_dat *dat)
{
	int	y;
	int x;
	int bar_y_size;

	y = -1;
	bar_y_size = 0;
	while (++y < dat->r.y)
	{
		x = -1;
		while (++x < dat->r.x)
			dat->img.data[y * dat->r.x + x] = dat->buf[y][x];
	}
	mlx_put_image_to_window(dat->mlx, dat->win, dat->img.img, 0, 0);
	if (dat->f_sh - 40 < dat->r.y)
		bar_y_size = dat->r.y - (dat->f_sh - 40);
	mlx_string_put(dat->mlx, dat->win, 4, dat->r.y - (dat->r.y * 2 / 100) \
			- bar_y_size, 0xffd56b, "point :");
	mlx_string_put(dat->mlx, dat->win, 60, dat->r.y - (dat->r.y * 2 / 100) \
			- bar_y_size, 0xffd56b, dat->txt);
}

void	key_update2(t_dat *dat)
{
	if (dat->k_a)
	{
		if (!dat->map.map[(int)(dat->p.x - dat->p.diry \
					* 2 * dat->movespeed)][(int)(dat->p.y)])
			dat->p.x -= dat->p.diry * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y \
					+ dat->p.dirx * dat->movespeed)])
			dat->p.y += dat->p.dirx * dat->movespeed;
	}
	if (dat->k_d)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.diry \
					* 2 * dat->movespeed)][(int)(dat->p.y)])
			dat->p.x += dat->p.diry * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y \
					- dat->p.dirx * dat->movespeed)])
			dat->p.y -= dat->p.dirx * dat->movespeed;
	}
	key_update3(dat, 0, 0);
}

int		key_update(t_dat *dat)
{
	if (dat->k_w)
	{
		if (!dat->map.map[(int)(dat->p.x + dat->p.dirx * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x += dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y + \
					dat->p.diry * dat->movespeed)])
			dat->p.y += dat->p.diry * dat->movespeed;
	}
	if (dat->k_s)
	{
		if (!dat->map.map[(int)(dat->p.x - dat->p.dirx * 2 * \
					dat->movespeed)][(int)(dat->p.y)])
			dat->p.x -= dat->p.dirx * dat->movespeed;
		if (!dat->map.map[(int)(dat->p.x)][(int)(dat->p.y - \
					dat->p.diry * dat->movespeed)])
			dat->p.y -= dat->p.diry * dat->movespeed;
	}
	key_update2(dat);
	map_update(dat);
	return (0);
}

void	input_buf(t_dat *dat, t_d *d, int x)
{
	int		y;
	double	dist;

	y = -1;
	if (d->side == 0)
		dist = d->sidedistx;
	else
		dist = d->sidedisty;
	while (++y < dat->r.y)
	{
		if (y < d->drawstart)
			dat->buf[y][x] = dat->ccolor;
		else if (y < d->drawend)
		{
			d->texy = (int)d->texpos & (64 - 1);
			d->texpos += d->step;
			d->color = dat->texture[d->texnum][64 * d->texy + d->texx];
			dat->buf[y][x] = convert_color(d->color, dist);
		}
		else
			dat->buf[y][x] = dat->fcolor;
	}
	dat->zbuf[x] = d->perpwalldist;
}

void	choice_tex(t_d *d)
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
