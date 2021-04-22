/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:36:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/20 22:24:56 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stack.h"

void	push_loc(t_stack *s, int x, int y, char **map)
{
	t_loc	loc;

	if (x < 0 || y < 0)
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
	{
		loc.x = x;
		loc.y = y;
		push(s, loc);
	}
}

void	map_print(char **map, int max_x)
{
	int i;

	i = -1;
	while (++i < max_x)
		printf("%s\n", map[i]);
	puts("");
}

void	zero_space_chk(char **map, int x, int y, t_dat *dat)
{
	if (map[x][y] == '0')
	{
		if (x != 0 && map[x - 1][y] == ' ')
			err_msg("minimap error");
		if ((x == dat->map.x - 1) && map[x + 1][y] == ' ')
			err_msg("minimap error");
		if (y != 0 && map[x][y - 1] == ' ')
			err_msg("minimap error");
		if (map[x][y + 1] == ' ' || map[x][y + 1] == 0)
			err_msg("minimap error");
	}
}

void	navi_map(t_loc *st, t_stack *s, t_dat *dat, char **map)
{
	int	x;
	int	y;

	while (1)
	{
		x = st->x;
		y = st->y;
		if (x == 0 || y == 0 || x == (dat->map.x - 1) || y == (dat->map.y - 1))
			break ;
		zero_space_chk(map, x, y, dat);
		map[x][y] = '*';
		map_print(map, dat->map.x);
		push_loc(s, x - 1, y, map);
		push_loc(s, x + 1, y, map);
		push_loc(s, x, y - 1, map);
		push_loc(s, x, y + 1, map);
		if (is_empty(s))
		{
			printf("sucessed\n");
			return ;
		}
		else
			*st = pop(s);
	}
	printf("Faild\n");
}

void	border_chk(t_dat *dat)
{
	t_loc	st;
	t_stack	s;

	init_stack(&s);
	st.x = dat->p.x;
	st.y = dat->p.y;
	navi_map(&st, &s, dat, dat->map.map);
}
