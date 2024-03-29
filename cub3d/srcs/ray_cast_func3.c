/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 02:34:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/04 10:35:06 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_update3(t_dat *dat, double olddirx, double oldplanex)
{
	olddirx = dat->p.dirx;
	if (dat->k_left)
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
	if (dat->k_right)
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

void	sort_order(t_pair *sp, int spnum)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < spnum)
	{
		j = -1;
		while (++j < spnum - 1)
			if (spnum == 1)
			{
				sp[0].first = 0;
				sp[0].second = 0;
			}
			else if (sp[j].first > sp[j + 1].first)
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

void	sort_sprite(t_i *s, int spnum)
{
	t_pair	*sp;
	int		i;

	i = -1;
	if (!(sp = malloc(sizeof(t_pair) * spnum)))
		err_msg("allocate error");
	while (++i < spnum)
	{
		sp[i].first = s->spdist[i];
		sp[i].second = s->spord[i];
	}
	sort_order(sp, spnum);
	i = -1;
	while (++i < spnum)
	{
		s->spdist[i] = sp[spnum - i - 1].first;
		s->spord[i] = sp[spnum - i - 1].second;
	}
	free(sp);
}

void	order_sprite(t_dat *dat, t_i *s)
{
	int i;

	i = -1;
	while (++i < dat->spnum)
	{
		s->spord[i] = i;
		s->spdist[i] = ((dat->p.x - dat->sp[i].x) * (dat->p.x - dat->sp[i].x) \
				+ (dat->p.y - dat->sp[i].y) * (dat->p.y - dat->sp[i].y));
	}
}

void	init_sprite(t_dat *dat, t_i *s)
{
	s->spord = malloc(sizeof(int) * dat->spnum);
	s->spdist = malloc(sizeof(double) * dat->spnum);
	order_sprite(dat, s);
	sort_sprite(s, dat->spnum);
	calc_sprite(dat, s);
	free(s->spord);
	free(s->spdist);
}
