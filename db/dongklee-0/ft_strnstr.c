/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:16:35 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 19:25:25 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_src;

	if (*needle == '\0')
		return ((char *)haystack);
	len_src = ft_strlen(needle);
	while ((*haystack != '\0') && (len_src <= len--))
	{
		if ((*haystack == *needle) &&
				ft_strncmp(haystack, needle, len_src) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
