/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:15:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/10 12:48:22 by jitlee           ###   ########.fr       */
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
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save\0", 7) == 0)
			dat.issave = 1;
		else
			err_msg("UNKNOWN ARGUMENT");
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		err_msg("SceneFile is not .cub File");
	ft_memset(&dat.f, -1, sizeof(dat.f));
	ft_memset(&dat.c, -1, sizeof(dat.c));
	dat.p.x = -1.0;
	dat.p.y = -1.0;
	map_chk(argv[1], &dat);
	border_chk(&dat);
	ray_cast(&dat);
}
