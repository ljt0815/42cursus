/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:45:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/10 14:01:36 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "stack.h"
# include "mlx.h"
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

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
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}			t_p;

typedef struct {
	int		bpp;
	int		*data;
	int		size_l;
	int		endian;
	int		img_width;
	int		img_height;
	void	*img;
}			t_img;

typedef struct {
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	wallx;
	double	step;
	double	texpos;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		mapx;
	int		mapy;
	int		texx;
	int		texy;
	int		color;
}			t_d;

typedef struct {
	double	x;
	double	y;
	int		texture;
}			t_sp;

typedef struct {
	double	first;
	int		second;
}			t_pair;

typedef struct {
	double	spx;
	double	spy;
	double	invd;
	double	tfx;
	double	tfy;
	double	*spdist;
	int		*spord;
	int		spscrx;
	int		vmoves;
	int		sph;
	int		drsty;
	int		dreny;
	int		spw;
	int		drstx;
	int		drenx;
	int		st;
	int		texx;
	int		y;
	int		d;
	int		texy;
	int		color;
}			t_i;

typedef	struct {
	char	bftype[2];
	int		size;
	char	bfreserv1[2];
	char	bfreserv2[2];
	int		bfoffbits;
	int		bisize;
	int		biwidth;
	int		biheight;
	char	biplanes[2];
	char	bibitcnt[2];
	int		bicomp;
	int		bisizeimg;
	int		bixppm;
	int		biyppm;
	int		biclrused;
	int		biclrimp;
}			t_bmp;

typedef struct {
	t_r		r;
	t_f		f;
	t_c		c;
	t_p		p;
	t_d		d;
	t_sp	*sp;
	t_map	map;
	t_img	img;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*txt;
	void	*mlx;
	void	*win;
	int		**buf;
	int		**texture;
	int		spnum;
	int		issave;
	int		k_w;
	int		k_s;
	int		k_a;
	int		k_d;
	int		k_left;
	int		k_right;
	int		fcolor;
	int		ccolor;
	int		eat_cnt;
	int		f_sw;
	int		f_sh;
	double	movespeed;
	double	rotspeed;
	double	*zbuf;
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
void		save_map(t_dat *dat, char **my_path);
void		map_valid_chk(int *fd, t_dat *dat, char *line);
void		border_chk(t_dat *dat);
char		*ft_mapcpy(const char *src, t_dat *dat, int i);
void		navi_map(t_loc *st, t_stack *s, t_dat *dat, char **map_tmp);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
int			xpm_chk3(char *line, t_dat *dat);
void		isdigit_chk(char ch, char flag);
void		player_dir(t_dat *dat, char news);
void		ray_cast(t_dat *dat);
void		map_word_chk(char num, t_dat *dat);
void		*ft_calloc(size_t count, size_t size);
void		ray_calc(t_dat *dat);
void		ray_draw(t_dat *dat);
int			key_update(t_dat *dat);
int			key_press(int key, t_dat *dat);
void		input_buf(t_dat *dat, t_d *d, int x);
void		choice_tex(t_d *d);
void		key_update3(t_dat *dat, double olddirx, double oldplanex);
void		calc_sprite(t_dat *dat, t_i *s);
void		init_sprite(t_dat *dat, t_i *s);
int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void		screenshot(t_dat *dat);
int			key_release(int key, t_dat *dat);
int			map_update(t_dat *dat);
char		*ft_itoa(int n);
int			xbutton(t_dat *dat);
void		stopmusic(void);
int			convert_color(int color, double dist);
void		get_scr_size(t_dat *dat);
int			move_mouse(t_dat *dat);
void		mouse_update(t_dat *dat, double olddirx, double oldplanex, int x);
#endif
