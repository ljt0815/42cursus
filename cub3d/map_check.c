/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/05 02:15:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

int		resol_check(char *line, t_dat *dat)
{
	if (*(line) != ' ')
		return (-1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->t_r.x = dat->t_r.x * 10 + (*(line) - '0');
		line++;
	}
	if (*(line) != ' ')
		return (-1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->t_r.y = dat->t_r.y * 10 + (*(line) - '0');
		line++;
	}
}

int		map_check(char *path, t_dat *dat)
{
	char *line;
	int fd;
	int i;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (line[0] == 'R')
			resol_check(line, t_dat *dat);
	}
	return (0);
}
