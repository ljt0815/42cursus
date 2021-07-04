/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:02:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 00:14:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
