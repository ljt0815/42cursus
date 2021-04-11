/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/11 09:35:05 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	resol_check(char *line, t_dat *dat)
{
	if (*(line) != ' ')
		exit(1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->r.x = dat->r.x * 10 + (*(line) - '0');
		line++;
	}
	if (*(line) != ' ')
		exit(1);
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->r.y = dat->r.y * 10 + (*(line) - '0');
		line++;
	}
}

void	path_check(char *line, t_dat *dat, char news)
{
	if (*(line) != ' ')
		exit(1);
	while (*(line) == ' ')
		line++;
	if (open(line, O_RDONLY) == -1)
		exit(1);
	if (news == 'n')
		dat->no = line;
	else if (news == 's')
		dat->so = line;
}

int		map_check(char *my_path, t_dat *dat)
{
	char	*line;
	int		fd;
	int		state;

	fd = open(my_path, O_RDONLY);
	while ((state = get_next_line(fd, &line)))
	{
		if (state == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (line[0] == 'R')
			resol_check(&line[1], dat);
		if (line[0] == 'N')
		{
			if (line[1] == 'O')
				path_check(&line[2], dat, 'n');
		}
		if (line[0] == 'S')
		{
			if (line[1] == 'O')
				path_check(&line[2], dat, 's');
		}
	}
	printf("x = %d\ny = %d\nNO=%s\nSO=%s\n", dat->r.y, dat->r.x, dat->no, dat->so);
	return (0);
}
