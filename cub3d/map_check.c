/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/08 19:06:32 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"
#include <stdio.h>

int		resol_check(char *line, t_dat *dat)
{
	if (*(line) != ' ')
		return (-1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->r.x = dat->r.x * 10 + (*(line) - '0');
		line++;
	}
	if (*(line) != ' ')
		return (-1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->r.y = dat->r.y * 10 + (*(line) - '0');
		line++;
	}
	return (1);
}

int		map_check(char *my_path, t_dat *dat)
{
	char *line;
	int fd;
	int i;
	int state;

	dat += 0;
	fd = open(my_path, O_RDONLY);
	while ((state = get_next_line(fd, &line)))
	{
		if (state == -1)
		{
			write(1, "error", 5);
			return (0);
		}
		i = 0;
		if (line[0] == 'R')
			resol_check(&line[1], dat);
	}
	printf("x = %d\ny = %d", dat->r.y, dat->r.x);
	return (0);
}
