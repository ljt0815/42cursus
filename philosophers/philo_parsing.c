/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 04:30:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/31 07:12:14 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\v' || \
			ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	parse_int(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (is_digit(str[i]))
		ret = (ret * 10) + (str[i++] - '0');
	if (str[i] != 0)
		return (-1);
	return (ret);
}

int	parse_arg(int ac, char *av[], t_dat *d)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (parse_int(av[i]) == -1)
			return (-1);
		else
		{
			d->args[i - 1] = parse_int(av[i]);
			if (d->args[i - 1] <= 0)
				return (-1);
		}
	}
	if (d->args[0] > 8192)
		return (-1);
	return (1);
}
