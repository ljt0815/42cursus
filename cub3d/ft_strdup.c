/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:13:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 04:28:42 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = -1;
	while (src[len])
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (src[++i])
		result[i] = src[i];
	result[i] = 0;
	return (result);
}
