/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 05:38:56 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/08 12:31:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_select(t_dat *dat, t_d *d)
{
	d->stepx = -1;
	d->sidedistx = (dat->p.x - d->mapx) * d->deltadistx;
	if (d->raydirx >= 0)
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - dat->p.x) * d->deltadistx;
	}
	d->stepy = -1;
	d->sidedisty = (dat->p.y - d->mapy) * d->deltadisty;
	if (d->raydiry >= 0)
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - dat->p.y) * d->deltadisty;
	}
}

void	calc_init(t_dat *dat, t_d *d, int x)
{
	d->camerax = 2 * x / (double)dat->r.x - 1;
	d->raydirx = dat->p.dirx + dat->p.planex * d->camerax;
	d->raydiry = dat->p.diry + dat->p.planey * d->camerax;
	d->mapx = (int)dat->p.x;
	d->mapy = (int)dat->p.y;
	d->deltadistx = sqrt(1 + (d->raydiry * d->raydiry) / \
			(d->raydirx * d->raydirx));
	d->deltadisty = sqrt(1 + (d->raydirx * d->raydirx) / \
			(d->raydiry * d->raydiry));
	d->hit = 0;
}

void	calc_dda(t_dat *dat, t_d *d)
{
	while (d->hit == 0)
	{
		if (d->sidedistx < d->sidedisty)
		{
			d->sidedistx += d->deltadistx;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->sidedisty += d->deltadisty;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (dat->map.map[d->mapx][d->mapy] > 0)
			d->hit = 1;
	}
	d->perpwalldist = (d->mapy - dat->p.y + \
			(1 - d->stepy) / 2) / d->raydiry;
	if (d->side == 0)
		d->perpwalldist = (d->mapx - dat->p.x + \
				(1 - d->stepx) / 2) / d->raydirx;
}

void	calc_screen(t_dat *dat, t_d *d)
{
	d->lineheight = (int)(dat->r.y / d->perpwalldist);
	d->drawstart = -(d->lineheight) / 2 + dat->r.y / 2;
	if (d->drawstart < 0)
		d->drawstart = 0;
	d->drawend = d->lineheight / 2 + dat->r.y / 2;
	if (d->drawend >= dat->r.y)
		d->drawend = dat->r.y - 1;
	choice_tex(d);
	if (d->side == 0)
		d->wallx = dat->p.y + d->perpwalldist * d->raydiry;
	else
		d->wallx = dat->p.x + d->perpwalldist * d->raydirx;
	d->wallx -= floor(d->wallx);
	d->texx = (int)(d->wallx * (double)64);
	if (d->side == 0 && d->raydirx > 0)
		d->texx = 64 - d->texx - 1;
	if (d->side == 1 && d->raydiry < 0)
		d->texx = 64 - d->texx - 1;
	d->step = 1.0 * 64 / d->lineheight;
	d->texpos = (d->drawstart - dat->r.y / 2 + d->lineheight / 2) * d->step;
}

void	ray_calc(t_dat *dat)
{
	int	x;
	t_d	d;
	t_i i;

	x = -1;
	while (++x < dat->r.x)
	{
		calc_init(dat, &d, x);
		calc_select(dat, &d);
		calc_dda(dat, &d);
		calc_screen(dat, &d);
		input_buf(dat, &d, x);
	}
	init_sprite(dat, &i);
}
