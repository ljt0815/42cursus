/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/15 19:37:34 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	err_msg(void)
{
	printf("Error\n");
	exit(1);
}

void	resol_chk(char *line, t_dat *dat)
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

void	path_chk(char *line, t_dat *dat, char news)
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

int		map_chk(char *my_path, t_dat *dat)
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
			resol_chk(&line[1], dat);
		}
		xpm_chk(line, dat);
		comma_chk(line, dat);
	}
	null_chk(dat);
	printf("x = %d\ny = %d\nNO=%s\nSO=%s\nWE=%s\nEA=%s\n", dat->r.y, dat->r.x, dat->no, dat->so, dat->we, dat->ea);
	printf("F.r=%d\nF.g=%d\nF.b=%d\n", dat->f.r, dat->f.g, dat->f.b);
	printf("C.r=%d\nC.g=%d\nC.b=%d\n", dat->c.r, dat->c.g, dat->c.b);
	return (0);
}
