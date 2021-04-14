/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:26:14 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/12 12:42:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_check2(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (dat->we == 0)
			path_check(&line[2], dat, 'w');
		else
			err_msg();
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (dat->ea == 0)
			path_check(&line[2], dat, 'e');
		else
			err_msg();
	}
}

void	xpm_check(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (dat->no == 0)
			path_check(&line[2], dat, 'n');
		else
			err_msg();
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (dat->so == 0)
			path_check(&line[2], dat, 's');
		else
			err_msg();
	}
	else
		xpm_check2(line, dat);
}

void	null_check(t_dat *dat)
{
	if (dat->no == 0)
		err_msg();
	else if (dat->so == 0)
		err_msg();
	else if (dat->we == 0)
		err_msg();
	else if (dat->ea == 0)
		err_msg();
	else if (dat->r.x == 0)
		err_msg();
	else if (dat->r.y == 0)
		err_msg();
}
