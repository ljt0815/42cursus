/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:49:37 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/19 09:49:52 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_mapcpy(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = -1;
	while (src[len])
		len++;
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	while (src[++i])
	{
		if (src[i] == ' ')
			result[i] = '0';
		else
			result[i] = src[i];
	}
	result[i] = 0;
	return (result);
}
