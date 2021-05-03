/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:42:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 04:30:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(count * size)))
		return (tmp);
	ft_bzero(tmp, count * size);
	return (tmp);
}
