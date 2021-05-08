/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:25:34 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/08 08:37:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_dat *dat)
{
	int i;

	i = -1;
	dat->mlx = mlx_init();
	mlx_get_screen_size(dat->mlx, &dat->f_sw, &dat->f_sh);
	if (dat->r.x > dat->f_sw)
		dat->r.x = dat->f_sw;
	if (dat->r.y > dat->f_sh)
		dat->r.y = dat->f_sh;
	if (!(dat->buf = ft_calloc(dat->r.y, sizeof(int *))))
		err_msg("memory allocate error");
	while (++i < dat->r.y)
		if (!(dat->buf[i] = ft_calloc(dat->r.x, sizeof(int))))
			err_msg("memory allocate error");
	if (!(dat->texture = ft_calloc(5, sizeof(int *))))
		err_msg("memory allocate error");
	i = -1;
	while (++i < 5)
		if (!(dat->texture[i] = ft_calloc(dat->r.x * dat->r.y, sizeof(int))))
			err_msg("memory allocate error");
	dat->movespeed = 0.07;
	dat->rotspeed = 0.07;
}

void	load_image(t_dat *dat, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	y = -1;
	img->img = mlx_xpm_file_to_image(dat->mlx, path, \
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
			&img->size_l, &img->endian);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(dat->mlx, img->img);
}

void	load_texture(t_dat *dat)
{
	t_img	img;

	load_image(dat, dat->texture[0], dat->no, &img);
	load_image(dat, dat->texture[1], dat->so, &img);
	load_image(dat, dat->texture[2], dat->we, &img);
	load_image(dat, dat->texture[3], dat->ea, &img);
	load_image(dat, dat->texture[4], dat->s, &img);
}

int		main_loop(t_dat *dat)
{
	ray_calc(dat);
	ray_draw(dat);
	if (dat->issave)
	{
		screenshot(dat);
		exit(1);
	}
	key_update(dat);
	return (0);
}

void	ray_cast(t_dat *dat)
{
	ray_init(dat);
	load_texture(dat);
	dat->zbuf = malloc(sizeof(double) * dat->r.x);
	if (dat->zbuf == 0)
		err_msg("allocate error");
	if (dat->issave)
		dat->win = mlx_new_window(dat->mlx, 0, 0, "mlx");
	else
		dat->win = mlx_new_window(dat->mlx, dat->r.x, dat->r.y, "mlx");
	dat->txt = ft_calloc(sizeof(char), 2);
	if (dat->txt == 0)
		err_msg("allocate error");
	dat->fcolor = dat->f.r * 256 + dat->f.g;
	dat->fcolor = dat->fcolor * 256 + dat->f.b;
	dat->ccolor = dat->c.r * 256 + dat->c.g;
	dat->ccolor = dat->ccolor * 256 + dat->c.b;
	system("afplay -v 0.30 mp3/MP_BGM.mp3 &>/dev/null &");
	dat->img.img = mlx_new_image(dat->mlx, dat->r.x, dat->r.y);
	dat->img.data = (int *)mlx_get_data_addr(dat->img.img, \
			&dat->img.bpp, &dat->img.size_l, &dat->img.endian);
	mlx_loop_hook(dat->mlx, &main_loop, dat);
	mlx_hook(dat->win, 17, 1L << 17, &xbutton, (void *)0);
	mlx_hook(dat->win, 2, 1, &key_press, dat);
	mlx_hook(dat->win, 3, 2, &key_release, dat);
	mlx_loop(dat->mlx);
}
