/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 05:58:13 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/10 17:23:43 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_sprite(t_dat *dat, t_i *s, int i)
{
	int st;
	int y;

	st = s->drstx - 1;
	while (++st < s->drenx)
	{
		s->texx = (int)((256 * (st - (-s->spw / 2 + s->spscrx)) \
					* 64 / s->spw) / 256);
		if (s->tfy > 0 && st > 0 && st < dat->r.x && s->tfy < dat->zbuf[st])
		{
			y = s->drsty - 1;
			while (++y < s->dreny)
			{
				s->d = (y - s->vmoves) * 256 - dat->r.y * 128 + s->sph * 128;
				s->texy = ((s->d * 64) / s->sph) / 256;
				s->color = dat->texture[dat->sp[s->spord[i]].texture]\
					[64 * s->texy + s->texx];
				if ((s->color & 0x00FFFFFF) != 0)
					dat->buf[y][st] = s->color;
			}
		}
	}
}

void	calc_sprite(t_dat *dat, t_i *s)
{
	int	i;

	i = -1;
	while (++i < dat->spnum)
	{
		s->spx = dat->sp[s->spord[i]].x - dat->p.x;
		s->spy = dat->sp[s->spord[i]].y - dat->p.y;
		s->invd = 1.0 / (dat->p.planex * \
				dat->p.diry - dat->p.dirx * dat->p.planey);
		s->tfx = s->invd * (dat->p.diry * s->spx - dat->p.dirx * s->spy);
		s->tfy = s->invd * (-dat->p.planey * s->spx + dat->p.planex * s->spy);
		s->spscrx = (int)((dat->r.x / 2) * (1 + s->tfx / s->tfy));
		s->vmoves = (int)(VMOVE / s->tfy);
		s->sph = (int)fabs((dat->r.y / s->tfy) / VDIV);
		if ((s->drsty = -s->sph / 2 + dat->r.y / 2 + s->vmoves) < 0)
			s->drsty = 0;
		if ((s->dreny = s->sph / 2 + dat->r.y / 2 + s->vmoves) >= dat->r.y)
			s->dreny = dat->r.y - 1;
		s->spw = (int)fabs((dat->r.y / s->tfy) / UDIV);
		if ((s->drstx = -s->spw / 2 + s->spscrx) < 0)
			s->drstx = 0;
		if ((s->drenx = s->spw / 2 + s->spscrx) >= dat->r.x)
			s->drenx = dat->r.x - 1;
		screen_sprite(dat, s, i);
	}
}

int		convert_color(int color, double dist)
{
	double r;
	double g;
	double b;

	if (dist < 11)
		return (color);
	b = (color % 256);
	color = (color - b) / 256;
	g = (color % 256);
	r = (color - g) / 256;
	dist -= 7;
	dist /= 4;
	r /= dist;
	g /= dist;
	b /= dist;
	return (((((int)r * 256) + (int)g) * 256) + (int)b);
}

void	get_scr_size(t_dat *dat)
{
	dat->movespeed = 0.07;
	dat->rotspeed = 0.07;
	mlx_get_screen_size(dat->mlx, &dat->f_sw, &dat->f_sh);
	if (dat->r.x > dat->f_sw)
		dat->r.x = dat->f_sw;
	if (dat->r.y > dat->f_sh)
		dat->r.y = dat->f_sh;
}
