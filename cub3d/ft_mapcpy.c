/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:49:37 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/29 20:07:03 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_mapcpy(const char *src, t_dat *dat)
{
	int		i;
	char	*result;

	i = -1;
	if ((result = (char *)malloc(sizeof(char) * dat->map.y + 1)) == 0)
		return (0);
	ft_memset(result, ' ', dat->map.y);
	result[dat->map.y] = 0;
	while (src[++i])
		result[i] = src[i];
	result[i] = 0;
	return (result);
}
