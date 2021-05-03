/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:49:33 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/04 08:49:31 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_bmp2(t_bmp *bmp, t_dat *dat, int *fd)
{
	bmp->biplanes[0] = 1;
	write(*fd, &bmp->biplanes[0], 1);
	bmp->biplanes[1] = 0;
	write(*fd, &bmp->biplanes[1], 1);
	bmp->bibitcnt[0] = 32;
	write(*fd, &bmp->bibitcnt[0], 1);
	bmp->bibitcnt[1] = 0;
	write(*fd, &bmp->bibitcnt[1], 1);
	bmp->bicomp = 0;
	write(*fd, &bmp->bicomp, 4);
	bmp->bisizeimg = 4 * dat->r.x * dat->r.y;
	write(*fd, &bmp->bisizeimg, 4);
	bmp->bixppm = dat->r.x;
	write(*fd, &bmp->bixppm, 4);
	bmp->biyppm = dat->r.y;
	write(*fd, &bmp->biyppm, 4);
	bmp->biclrused = 0x00ffffff;
	write(*fd, &bmp->biclrused, 4);
	bmp->biclrimp = 0;
	write(*fd, &bmp->biclrimp, 4);
}

void	init_bmp(t_bmp *bmp, t_dat *dat, int *fd)
{
	bmp->bftype[0] = 'B';
	write(*fd, &bmp->bftype[0], 1);
	bmp->bftype[1] = 'M';
	write(*fd, &bmp->bftype[1], 1);
	bmp->size = 54 + 4 * dat->r.x * dat->r.y;
	write(*fd, &bmp->size, 4);
	ft_bzero(bmp->bfreserv1, 2);
	write(*fd, &bmp->bfreserv1[0], 2);
	ft_bzero(bmp->bfreserv2, 2);
	write(*fd, &bmp->bfreserv2[0], 2);
	bmp->bfoffbits = 54;
	write(*fd, &bmp->bfoffbits, 4);
	bmp->bisize = 40;
	write(*fd, &bmp->bisize, 4);
	bmp->biwidth = dat->r.x;
	write(*fd, &bmp->biwidth, 4);
	bmp->biheight = -dat->r.y;
	write(*fd, &bmp->biheight, 4);
	init_bmp2(bmp, dat, fd);
}

void	screenshot(t_dat *dat)
{
	t_bmp	bmp;
	int		fd;
	int		i;

	fd = open("screen_shot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	init_bmp(&bmp, dat, &fd);
	i = -1;
	while (++i < (dat->img.size_l / 4) * dat->r.y)
		if (i % (dat->img.size_l / 4) < dat->r.x)
			write(fd, &dat->img.data[i], 4);
	close(fd);
}
