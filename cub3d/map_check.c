/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/11 19:20:02 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	err_msg(void)
{
	printf("Error\n");
	exit(1);
}

void	resol_check(char *line, t_dat *dat)
{
	if (*(line) != ' ')
		err_msg();
	while (*(line) == ' ')
		line++;
	while (ft_isdigit(*(line)))
	{
		dat->r.x = dat->r.x * 10 + (*(line) - '0');
		line++;
	}
	if (*(line) != ' ')
		err_msg();
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
		err_msg();
	while (*(line) == ' ')
		line++;
	if (open(line, O_RDONLY) == -1)
		err_msg();
	if (news == 'n')
		dat->no = line;
	else if (news == 's')
		dat->so = line;
	else if (news == 'w')
		dat->we = line;
	else if (news == 'e')
		dat->ea = line;
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
			err_msg();
		if (line[0] == 'R')
		{	
			if (dat->r.x != 0 || dat->r.y != 0)
				err_msg();
			resol_check(&line[1], dat);
		}
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
		if (line[0] == 'W')
		{
			if (line[1] == 'E')
				path_check(&line[2], dat, 'w');
		}
		if (line[0] == 'E')
		{
			if (line[1] == 'A')
				path_check(&line[2], dat, 'e');
		}

		
	}
	printf("x = %d\ny = %d\nNO=%s\nSO=%s\nWE=%s\nEA=%s", dat->r.y, dat->r.x, dat->no, dat->so, dat->we, dat->ea);
	return (0);
}
