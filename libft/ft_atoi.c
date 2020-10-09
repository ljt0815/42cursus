/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:28:26 by jitlee            #+#    #+#             */
/*   Updated: 2020/10/09 15:08:41 by jitlee           ###   ########.fr       */
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
	int i;
	int sign;
	int tmp;
	int result;

	i = 0;
	sign = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (issign(str[i]))
	{
		if (issign(str[i]) == 1)
			sign = 1;
		i++;
	}
	while (isnum(str[i]))
	{
		tmp = str[i] - '0';
		result = (result * 10) + tmp;
		i++;
	}
	if (sign == 1)
		result = result * -1;
	return (result);
}
