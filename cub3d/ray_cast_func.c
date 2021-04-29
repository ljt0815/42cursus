/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 05:38:56 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/30 05:45:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_select(t_dat *dat, t_d *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (dat->p.x - d->mapx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - dat->p.x) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (dat->p.y - d->mapy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - dat->p.y) * d->deltadisty;
	}
}

void	calc_init(t_dat *dat, t_d *d, int x)
{
	d->camerax = 2 * x / (double)dat->p.x - 1;
	d->raydirx = dat->p.x + dat->p.planex * d->camerax;
	d->raydiry = dat->p.y + dat->p.planey * d->camerax;
	d->mapx = (int)dat->p.x;
	d->mapy = (int)dat->p.y;
	d->deltadistx = sqrt(1 + (d->raydiry * d->raydiry) / (d->raydirx * d->raydirx));
	d->deltadisty = sqrt(1 + (d->raydirx * d->raydirx) / (d->raydiry * d->raydiry));
	d->hit = 0;
	calc_select(dat, d);
}

void	ray_calc(t_dat *dat)
{
	int	x;
	int	y;
	t_d	d;

	y = -1;
	x = -1;
	while (++x < dat->r.x)
	{
		calc_init(dat, &d, x);
	}
}
