/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 04:30:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/30 04:46:28 by jitlee           ###   ########.fr       */
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
	while (is_space(str[i++]))
		;
	while (is_digit(str[i]))
		ret = (ret * 10) + (str[i++] - '0');
	while (is_space(str[i++]))
		;
	if (str[i] != 0)
		return (-1);
	return (1);
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
			d->args[i - 1] = parse_int(av[i]);
	}
	return (1);
}
