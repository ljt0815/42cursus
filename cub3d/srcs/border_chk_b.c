/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:36:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/08 15:25:46 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stack.h"

void	push_loc(t_stack *s, int x, int y, char **map)
{
	t_loc	loc;

	if (x < 0 || y < 0)
		return ;
	if (map[x][y] == 0 || map[x][y] == 2 || \
			map[x][y] == 3 || map[x][y] == 4)
	{
		loc.x = x;
		loc.y = y;
		push(s, loc);
	}
}

void	map_print(char **map, int max_x, int map_y)
{
	int i;
	int j;

	i = -1;
	while (++i < max_x)
	{
		j = -1;
		while (++j < map_y)
			printf("%d\t", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void	zero_space_chk(char **map, int x, int y, t_dat *dat)
{
	if (x != 0 && map[x - 1][y] == -16)
		err_msg("minimap error");
	if ((x <= dat->map.x - 1) && map[x + 1][y] == -16)
		err_msg("minimap error");
	if (y != 0 && map[x][y - 1] == -16)
		err_msg("minimap error");
	if (map[x][y + 1] == -16)
		err_msg("minimap error");
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
			err_msg("minimap border not invalid");
		zero_space_chk(map, x, y, dat);
		map[x][y] = 88;
		push_loc(s, x - 1, y, map);
		push_loc(s, x + 1, y, map);
		push_loc(s, x, y - 1, map);
		push_loc(s, x, y + 1, map);
		if (is_empty(s))
			return ;
		else
			*st = pop(s);
	}
}

void	border_chk(t_dat *dat)
{
	int		i;
	int		j;
	t_loc	st;
	t_stack	s;

	i = -1;
	init_stack(&s);
	st.x = dat->p.x;
	st.y = dat->p.y;
	navi_map(&st, &s, dat, dat->map.map);
	while (++i < dat->map.x)
	{
		j = -1;
		while (++j < dat->map.y)
			if (dat->map.map[i][j] == 88)
				dat->map.map[i][j] = 0;
	}
}
