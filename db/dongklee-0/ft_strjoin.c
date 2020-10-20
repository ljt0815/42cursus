/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:52:39 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:33:49 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mal_s;
	size_t	len;
	size_t	idx;

	if (s1 == NULL & s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mal_s = (char *)malloc(sizeof(char) * len);
	if (mal_s == NULL)
		return (0);
	idx = ft_strlcpy(mal_s, s1, len);
	ft_strlcat((mal_s + idx), s2, len);
	return (mal_s);
}
