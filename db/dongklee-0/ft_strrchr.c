/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:18:50 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 19:12:29 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	temp_c;
	size_t	s_len;

	temp_c = (char)c;
	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == temp_c)
			return ((char *)s + s_len);
		s_len--;
	}
	if (s[s_len] == temp_c)
		return ((char *)s + s_len);
	return (0);
}
