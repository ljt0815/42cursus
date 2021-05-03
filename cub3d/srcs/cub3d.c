/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:15:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/04 06:08:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_dat dat;

	if (argc > 3)
		err_msg("TOO MANY ARGUMENTS");
	else if (argc < 2)
		err_msg("I NEED MAP ARGUMENT");
	ft_bzero(&dat, sizeof(dat));
	ft_memset(&dat.f, -1, sizeof(dat.f));
	ft_memset(&dat.c, -1, sizeof(dat.c));
	dat.p.x = -1.0;
	dat.p.y = -1.0;
	dat.spnum = 0;
	map_chk(argv[1], &dat);
	system("leaks cub3D > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	border_chk(&dat);
	ray_cast(&dat);
}
