/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 02:34:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 05:54:36 by jitlee           ###   ########.fr       */
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

void	sort_order(t_pair *sp, int numsp)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < numsp)
	{
		j = -1;
		while (++j < numsp - 1)
		{
			if (sp[j].first > sp[j + 1].first)
			{
				tmp.first = sp[j].first;
				tmp.second = sp[j].second;
				sp[j].first = sp[j + 1].first;
				sp[j].second = sp[j + 1].second;
				sp[j + 1].first = tmp.first;
				sp[j + 1].second = tmp.second;
			}
		}
	}
}

void	sort_sprite(int	*spord, double *spdist, int numsp)
{
	t_pair	*sp;
	int		i;

	i = -1;
	if ((sp = malloc(sizeof(t_pair) * numsp)))
		err_msg("allocate error");
	while (++i < numsp)
	{
		sp[i].first = spdist[i];
		sp[i].second = spord[i];
	}
	sort_order(sp, numsp);
	i = -1;
	while (++i < numsp)
	{
		spdist[i] = sp[numsp - i - 1].first;
		spord[i] = sp[numsp = i - 1].second;
	}
	free(sp);
}

void	order_sprite(t_dat *dat, t_i *s, t_d *d)
{
	int i;

	i = -1;
	while (++i < dat->numsp)
	{
		s->spord[i] = i;
		s->spdist[i] = ((dat->p.x - dat->sp[i].x) * (dat->p.x - dat->sp[i].x) \
				+ (dat->p.y - dat->sp[i].y) * (dat->p.y - dat->sp[i].y);
	}
}

void	calc_sprite(t_dat *dat, t_i *s, t_d *d)
{
	order_sprite(dat, s, d);
	sort_sprite(s->spord, s->spdist, dat->numsp);
}
