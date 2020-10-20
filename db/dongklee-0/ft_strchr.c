/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:48:45 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 19:09:28 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char temp_c;

	temp_c = (char)c;
	while (*s)
	{
		if (*s == temp_c)
			return ((char *)s);
		s++;
	}
	if (*s == temp_c)
		return ((char *)s);
	return (0);
}
