/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:28:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/04 23:22:37 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char str)
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

int	issign(char str)
{
	if (str == '-')
		return (1);
	else if (str == '+')
		return (2);
	return (0);
}

int	isnum(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

unsigned long long	convert_num(const char *str, long *sign, long *num_len)
{
	long				i;
	unsigned long long	num;

	i = 0;
	*sign = 1;
	num = 0;
	*num_len = 0;
	while (is_space(str[i]))
		i++;
	if (issign(str[i]))
	{
		if (issign(str[i]) == 1)
			*sign = -1;
		i++;
	}
	while (isnum(str[i]))
	{
		num = (num * 10) + str[i] - '0';
		*num_len += 1;
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	long				sign;
	long				num_len;

	result = convert_num(str, &sign, &num_len);
	if (num_len > 19 || result > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (result * sign);
}
