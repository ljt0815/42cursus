/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:02:26 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/11 19:47:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *result;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((result = (char *)malloc(len + 1)) == 0)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
