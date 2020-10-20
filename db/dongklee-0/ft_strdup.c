/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:05:12 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:44:40 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	size_t	idx;
	char	*dup;

	s_len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dup == NULL)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		dup[idx] = s1[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}
