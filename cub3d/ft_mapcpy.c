/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:49:37 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 08:08:55 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_news(char news)
{
	if (news == 'N' || news == 'S')
		return (1);
	else if (news == 'E' || news == 'W')
		return (1);
	return (0);
}

char	*ft_mapcpy(const char *src, t_dat *dat, int i)
{
	int		j;
	char	*result;

	j = -1;
	if (!(result = (char *)malloc(sizeof(char) * dat->map.y + 1)))
		return (0);
	ft_memset(result, -16, dat->map.y);
	result[dat->map.y] = -48;
	while (src[++j])
	{
		if (is_news(src[j]))
			result[j] = 0;
		else
			result[j] = src[j] - '0';
		if (src[j] == '2')
		{
			dat->sp[dat->spnum].x = i + 0.5;
			dat->sp[dat->spnum].y = j + 0.5;
			dat->sp[dat->spnum].texture = 4;
			dat->spnum += 1;
		}
	}
	return (result);
}
