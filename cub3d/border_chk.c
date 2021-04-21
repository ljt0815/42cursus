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

void	push_loc(t_stack *s, int x, int y, char **map_tmp)
{
	t_loc	loc;

	if (x < 0 || y < 0)
		return ;
	if (map_tmp[x][y] == '0' || map_tmp[x][y] == '2')
	{
		loc.x = x;
		loc.y = y;
		push(s, loc);
	}
}

void	map_print(char **map_tmp, int max_x)
{
	int i;

	i = -1;
	while (++i < max_x)
		printf("%s\n", map_tmp[i]);
	puts("");
}

void	navi_map(t_loc *st, t_stack *s, t_dat *dat, char **map_tmp)
{
	int	x;
	int	y;

	while (1)
	{
		x = st->x;
		y = st->y;
		if (x == 0 || y == 0 || x == (dat->map.x - 1) || y == (dat->map.y - 1))
			break ;
		map_tmp[x][y] = '*';
		map_print(map_tmp, dat->map.x);
		push_loc(s, x - 1, y, map_tmp);
		push_loc(s, x + 1, y, map_tmp);
		push_loc(s, x, y - 1, map_tmp);
		push_loc(s, x, y + 1, map_tmp);
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

void	zero_space_chk(t_dat *dat, int i, int j)
{
	while (++i < dat->map.x)
	{
		j = -1;
		while (dat->map.map[i][++j])
		{
			if (dat->map.map[i][j] == '0')
			{
				if (i != 0 && dat->map.map[i - 1][j] == ' ')
					err_msg("minimap error");
				if ((i == dat->map.x - 1) && dat->map.map[i + 1][j] == ' ')
					err_msg("minimap error");
				if (j != 0 && dat->map.map[i][j - 1] == ' ')
					err_msg("minimap error");
				if (dat->map.map[i][j + 1] == ' ')
					err_msg("minimap error");
			}
		}
	}
}

void	border_chk(t_dat *dat, int i)
{
	char	**map_tmp;
	t_loc	st;
	t_stack	s;

	init_stack(&s);
	st.x = dat->p.x;
	st.y = dat->p.y;
	zero_space_chk(dat, -1, -1);
	map_tmp = malloc(sizeof(char *) * (dat->map.x + 1));
	while (++i < dat->map.x)
		map_tmp[i] = ft_mapcpy(dat->map.map[i]);
	navi_map(&st, &s, dat, map_tmp);
}
