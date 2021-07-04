/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:13:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 00:12:37 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = -1;
	while (src[len])
		len++;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == 0)
		return (0);
	while (src[++i])
		result[i] = src[i];
	result[i] = 0;
	return (result);
}
