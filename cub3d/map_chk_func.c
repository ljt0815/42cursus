/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:26:14 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/16 09:23:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		xpm_chk2(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (dat->we == 0)
		{
			path_chk(&line[2], dat, 'w');
			return (1);
		}
		else
			err_msg("Duplicate Identifier \"WE\"");
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (dat->ea == 0)
		{
			path_chk(&line[2], dat, 'e');
			return (1);
		}
		else
			err_msg("Duplicate Identifier \"EA\"");
	}
	return (0);
}

int		xpm_chk(char *line, t_dat *dat)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (dat->no == 0)
		{
			path_chk(&line[2], dat, 'n');
			return (1);
		}
		else
			err_msg("Duplicate Identifier \"NO\"");
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (dat->so == 0)
		{
			path_chk(&line[2], dat, 's');
			return (1);
		}
		else
			err_msg("Duplicate Identifier \"SO\"");
	}
	else if(xpm_chk2(line, dat))
		return (1);
	return (0);
}

void	null_chk(t_dat *dat)
{
	if (dat->no == 0)
		err_msg("NULL Identifier \"NO\"");
	else if (dat->so == 0)
		err_msg("NULL Identifier \"SO\"");
	else if (dat->we == 0)
		err_msg("NULL Identifier \"WE\"");
	else if (dat->ea == 0)
		err_msg("NULL Identifier \"EA\"");
	else if (dat->r.x == 0)
		err_msg("Resolution Width Zero or NULL");
	else if (dat->r.y == 0)
		err_msg("Resolution Height Zero or NULL");
	else if (dat->f.r == -1)
		err_msg("NULL Identifier \"F\"");
	else if (dat->c.r == -1)
		err_msg("NULL Identifier \"C\"");
}

int		comma_chk(char *line, t_dat *dat)
{
	if (*(line) == 'F')
	{
		f_chk(line, dat);
		rgb_valid_chk(dat, 'f');
		return (1);
	}
	else if (*(line) == 'C')
	{
		c_chk(line, dat);
		rgb_valid_chk(dat, 'c');
		return (1);
	}
	return (0);
}
