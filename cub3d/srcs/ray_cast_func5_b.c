/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_func5_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 06:33:14 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/08 09:25:58 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stopmusic(void)
{
	system("ps -ef | grep afplay | grep -v 'grep' | awk '{print $2}' > list");
	system("./turnoff.sh ; rm list");
	printf("success music stopping!!");
}

int		map_update(t_dat *dat)
{
	int		i;

	i = -1;
	while (++i < dat->spnum)
		if ((int)dat->p.x == (int)dat->sp[i].x)
			if ((int)dat->p.y == (int)dat->sp[i].y)
			{
				dat->sp[i].x = 0;
				dat->sp[i].y = 0;
				dat->sp[i].texture = -1;
				dat->spnum -= 1;
				dat->sp[i] = dat->sp[dat->spnum];
				dat->eat_cnt += 1;
				system("afplay -v 0.30 mp3/MP_eat.mp3 &>/dev/null &");
				free(dat->txt);
				dat->txt = ft_itoa(dat->eat_cnt);
			}
	return (0);
}

int		xbutton(t_dat *dat)
{
	dat += 0;
	stopmusic();
	exit(1);
	return (0);
}
