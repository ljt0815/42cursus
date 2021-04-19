/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:36:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/19 10:54:52 by jitlee           ###   ########.fr       */
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

void	map_print(char **map_tmp, int max_x, int max_y)
{
	int i;

	i = -1;
	while (++i < max_y)
		printf("%s\n", map_tmp[i]); 
	puts("");
}

void	border_chk(t_dat *dat)
{
	int		i;
	int		x;
	int		y;
	char	**map_tmp;
	t_loc	st;
	t_stack	s;

	init_stack(&s);
	i = -1;
	st.x = dat->p.x;
	st.y = dat->p.y;
	map_tmp = malloc(sizeof(char *) * (dat->map.y + 1));
	while (++i < dat->map.y)
		map_tmp[i] = ft_mapcpy(dat->map.map[i]);
	while (1)
	{
		x = st.x;
		y = st.y;
		if (x == 0 || y == 0 || x == (dat->map.y - 1) || y == (dat->map.x - 1))
			break;
		map_tmp[x][y] = '*';
		map_print(map_tmp, dat->map.x, dat->map.y);
		push_loc(&s, x - 1, y, map_tmp);
		push_loc(&s, x + 1, y, map_tmp);
		push_loc(&s, x, y - 1, map_tmp);
		push_loc(&s, x, y + 1, map_tmp);
		if (is_empty(&s))
		{
			printf("sucessed\n");
			return ;
		}
		else
			st = pop(&s);
	}
	printf("Faild\n");
}		
