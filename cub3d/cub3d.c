/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:15:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/19 09:34:37 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print(t_dat *dat)
{
	int i;

	i = -1;
	printf("x = %d\ny = %d\nNO=%s\nSO=%s\nWE=%s\nEA=%s\n", dat->r.y, dat->r.x, dat->no, dat->so, dat->we, dat->ea);
	printf("F.r=%d\nF.g=%d\nF.b=%d\n", dat->f.r, dat->f.g, dat->f.b);
	printf("C.r=%d\nC.g=%d\nC.b=%d\n", dat->c.r, dat->c.g, dat->c.b);
	printf("p.x=%d\np.y=%d\n", dat->p.x, dat->p.y);
	printf("map.size = %d\n", dat->map.size);
	while (++i < dat->map.size)
		printf("%s\n", dat->map.map[i]);
}

int		main(void)
{
	t_dat dat;

	dat.map.size = 0;
	ft_bzero(&dat, sizeof(dat));
	ft_memset(&dat.f, -1, sizeof(dat.f));
	ft_memset(&dat.c, -1, sizeof(dat.c));
	ft_memset(&dat.p, -1, sizeof(dat.p));
	map_chk("./test_map.cub", &dat);
	debug_print(&dat);
}
