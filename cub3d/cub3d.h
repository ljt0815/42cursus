/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:45:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/15 19:49:31 by jitlee           ###   ########.fr       */
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
	t_r		r;
	t_f		f;
	t_c		c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_dat;

void		path_chk(char *line, t_dat *dat, char news);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			map_chk(char *path, t_dat *dat);
void		ft_bzero(void *s, size_t n);
void		err_msg(char *msg);
void		xpm_chk(char *line, t_dat *dat);
void		null_chk(t_dat *dat);
void		comma_chk(char *line, t_dat *dat);
void		*ft_memset(void *b, int c, size_t len);
void		f_chk(char *line, t_dat *dat);
void		c_chk(char *line, t_dat *dat);
void		rgb_valid_chk(t_dat *dat, char fc);
#endif
