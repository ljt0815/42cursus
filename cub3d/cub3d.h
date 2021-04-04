/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:45:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/05 02:25:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>

typedef struct {
	int x;
	int y;
}		t_r;

typedef struct {
	t_r	resolution;
}		t_dat;
int		ft_isdigit(int c);
int		map_check(char *path, t_dat *dat);
void	ft_bzero(void *s, size_t n);
#endif
