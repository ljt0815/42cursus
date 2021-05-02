/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:49:37 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 04:28:27 by jitlee           ###   ########.fr       */
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

char	*ft_mapcpy(const char *src, t_dat *dat)
{
	int		i;
	char	*result;

	i = -1;
	if (!(result = (char *)malloc(sizeof(char) * dat->map.y + 1)))
		return (0);
	ft_memset(result, -16, dat->map.y);
	result[dat->map.y] = -48;
	while (src[++i])
	{
		if (is_news(src[i]))
			result[i] = 0;
		else
			result[i] = src[i] - '0';
	}
	return (result);
}
