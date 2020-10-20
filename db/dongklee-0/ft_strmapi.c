/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:06:25 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:10:01 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*result;

	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	idx = 0;
	while (s[idx])
	{
		result[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
