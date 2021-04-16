/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:33:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/16 10:44:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	err_msg(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(1);
}

void	path_chk(char *line, t_dat *dat, char news)
{
	if (*(line) != ' ')
		err_msg("Identifier : NEWS");
	while (*(line) == ' ')
		line++;
	if (ft_strncmp(&line[ft_strlen(line) - 4], ".xpm", 4) != 0)
		err_msg("TextureFile is not xpmFile");
	if (open(line, O_RDONLY) == -1)
		err_msg("TextureFile Can't Open");
	if (news == 'n')
		dat->no = ft_strdup(line);
	else if (news == 's')
		dat->so = ft_strdup(line);
	else if (news == 'w')
		dat->we = ft_strdup(line);
	else if (news == 'e')
		dat->ea = ft_strdup(line);
}

void	map_chk(char *my_path, t_dat *dat)
{
	char	*line;
	int		fd;
	int		state;

	fd = open(my_path, O_RDONLY);
	while ((state = get_next_line(fd, &line)))
	{
		if (state == -1)
			err_msg(".cub File Exception");
		else if (line[0] == 'R')
		{
			if (dat->r.x != 0 || dat->r.y != 0)
				err_msg("Duplicate Identifier \"R\"");
			resol_chk(&line[1], dat);
		}
		else if (xpm_chk(line, dat) || comma_chk(line, dat) || line[0] == '\0')
			;
		else
			break ;
		free(line);
	}
	null_chk(dat);
	//map_valid_chk(fd, dat);
}
