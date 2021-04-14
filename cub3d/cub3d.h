/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:45:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/14 23:37:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct {
	int		x;
	int		y;
}			t_r;

typedef struct {
	t_r		r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_dat;

void		path_check(char *line, t_dat *dat, char news);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			map_check(char *path, t_dat *dat);
void		ft_bzero(void *s, size_t n);
void		err_msg(void);
void		xpm_check(char *line, t_dat *dat);
void		null_check(t_dat *dat);
#endif
