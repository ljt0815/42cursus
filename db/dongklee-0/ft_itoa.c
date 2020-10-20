/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:53:41 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/18 18:43:03 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		len;

	nbr = n;
	len = ft_numlen(nbr);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len--] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	else if (nbr == 0)
		result[0] = '0';
	while (nbr)
	{
		result[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}
