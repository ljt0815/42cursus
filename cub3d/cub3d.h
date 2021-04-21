/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:45:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/20 22:27:37 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "stack.h"

typedef struct {
	int		x;
	int		y;
}			t_r;

typedef struct {
	int		r;
	int		g;
	int		b;
}			t_f;

typedef struct {
	int		r;
	int		g;
	int		b;
}			t_c;

typedef struct {
	int		x;
	int		y;
	char	**map;
}			t_map;

typedef struct {
	int		x;
	int		y;
}			t_p;

typedef struct {
	t_r		r;
	t_f		f;
	t_c		c;
	t_p		p;
	t_map	map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_dat;

void		player_chk(t_dat *dat, char *line);
void		path_chk(char *line, t_dat *dat, char news);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
void		map_chk(char *path, t_dat *dat);
void		ft_bzero(void *s, size_t n);
void		err_msg(char *msg);
int			xpm_chk(char *line, t_dat *dat);
void		null_chk(t_dat *dat);
int			comma_chk(char *line, t_dat *dat);
void		*ft_memset(void *b, int c, size_t len);
void		f_chk(char *line, t_dat *dat);
void		c_chk(char *line, t_dat *dat);
void		rgb_valid_chk(t_dat *dat, char fc);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *src);
void		resol_chk(char *line, t_dat *dat);
void		save_map(t_dat *dat, char *my_path);
void		map_valid_chk(int fd, t_dat *dat, char *line);
void		border_chk(t_dat *dat);
char		*ft_mapcpy(const char *src);
void		navi_map(t_loc *st, t_stack *s, t_dat *dat, char **map_tmp);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
#endif
