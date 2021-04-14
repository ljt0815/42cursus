/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:26:14 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/15 02:47:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_chk2(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (dat->we == 0)
			path_chk(&line[2], dat, 'w');
		else
			err_msg();
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (dat->ea == 0)
			path_chk(&line[2], dat, 'e');
		else
			err_msg();
	}
}

void	xpm_chk(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (dat->no == 0)
			path_chk(&line[2], dat, 'n');
		else
			err_msg();
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (dat->so == 0)
			path_chk(&line[2], dat, 's');
		else
			err_msg();
	}
	else
		xpm_chk2(line, dat);
}

void	null_chk(t_dat *dat)
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

void	comma_chk(char *line, t_dat *dat)
{
	
}
