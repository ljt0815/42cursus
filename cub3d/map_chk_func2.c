/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:30:22 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/19 09:04:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_chk(char *line, t_dat *dat)
{
	if (dat->f.r != -1)
		err_msg("Duplicate Identifier \"F\"");
	else
		ft_bzero(&(dat->f), 12);
	if (*(++line) != ' ')
		err_msg("Identifier \"F\" Exception");
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*line))
		dat->f.r = (dat->f.r * 10) + *(line++) - '0';
	if (*(line) != ',')
		err_msg("Identifier \"F\" Exception");
	while (ft_isdigit(*(++line)))
		dat->f.g = (dat->f.g * 10) + *(line) - '0';
	if (*(line) != ',')
		err_msg("Identifier \"F\" Exception");
	while (ft_isdigit(*(++line)))
		dat->f.b = (dat->f.b * 10) + *(line) - '0';
	while (*(line) == ' ')
		line++;
	if (*(line) != '\0')
		err_msg("Identifier \"F\" Exception");
}

void	c_chk(char *line, t_dat *dat)
{
	if (dat->c.r != -1)
		err_msg("Duplicate Identifier \"C\"");
	else
		ft_bzero(&(dat->c), 12);
	if (*(++line) != ' ')
		err_msg("Identifier \"C\" Exception");
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*line))
		dat->c.r = (dat->c.r * 10) + *(line++) - '0';
	if (*(line) != ',')
		err_msg("Identifier \"C\" Exception");
	while (ft_isdigit(*(++line)))
		dat->c.g = (dat->c.g * 10) + *(line) - '0';
	if (*(line) != ',')
		err_msg("Identifier \"C\" Exception");
	while (ft_isdigit(*(++line)))
		dat->c.b = (dat->c.b * 10) + *(line) - '0';
	while (*(line) == ' ')
		line++;
	if (*(line) != '\0')
		err_msg("Identifier \"C\" Exception");
}

void	rgb_valid_chk(t_dat *dat, char fc)
{
	if (fc == 'c')
	{
		if (!(dat->c.r >= 0 && dat->c.r <= 255))
			err_msg("Identifier \"C\" Exception");
		if (!(dat->c.g >= 0 && dat->c.g <= 255))
			err_msg("Identifier \"C\" Exception");
		if (!(dat->c.b >= 0 && dat->c.b <= 255))
			err_msg("Identifier \"C\" Exception");
	}
	else if (fc == 'f')
	{
		if (!(dat->f.r >= 0 && dat->f.r <= 255))
			err_msg("Identifier \"F\" Exception");
		if (!(dat->f.g >= 0 && dat->f.g <= 255))
			err_msg("Identifier \"F\" Exception");
		if (!(dat->f.b >= 0 && dat->f.b <= 255))
			err_msg("Identifier \"F\" Exception");
	}
}

void	player_chk(t_dat *dat, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || \
				line[i] == 'E' || line[i] == 'W')
		{
			if (dat->p.x == -1)
			{
				dat->p.x = dat->map.size;
				dat->p.y = i;
			}
			else
				err_msg("Player ONLY ONE");
		}
		i++;
	}
	dat->map.size++;
}
