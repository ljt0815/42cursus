/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:28:26 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/11 19:18:49 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char str)
{
	if (str == '\r')
		return (1);
	else if (str == '\f')
		return (1);
	else if (str == '\n')
		return (1);
	else if (str == '\v')
		return (1);
	else if (str == '\t')
		return (1);
	else if (str == ' ')
		return (1);
	return (0);
}

int		issign(char str)
{
	if (str == '-')
		return (1);
	else if (str == '+')
		return (2);
	return (0);
}

int		isnum(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	long				i;
	long				sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (issign(str[i]))
	{
		if (issign(str[i]) == 1)
			sign = -1;
		i++;
	}
	while (isnum(str[i]))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if ( i > 19 || result > 9223372036854775807)
		return ((sign == 1) ? -1 : 0);
	return (result * sign);
}
