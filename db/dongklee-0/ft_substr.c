/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:40:39 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/10 16:50:29 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*mal_s;

	if (s == NULL)
		return (0);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_calloc(1, sizeof(char)));
	mal_s = (char *)malloc(sizeof(char) * (len + 1));
	if (mal_s == NULL)
		return (0);
	ft_strlcpy(mal_s, (s + start), (len + 1));
	return (mal_s);
}
