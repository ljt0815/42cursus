/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:45:30 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 06:28:47 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	parse_num(int pid, int len)
{
	unsigned int	i;

	i = 2147483648;
	while (i > 0)
	{
		if (len & i)
			send_signal(pid, SIGUSR2);
		else
			send_signal(pid, SIGUSR1);
		i >>= 1;
	}
}

void	parse_ch(int pid, char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i] != 0)
	{
		j = 128;
		while (j > 0)
		{
			if (s[i] & j)
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			j >>= 1;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	write(1, "client pid :", 12);
	ft_putnbr(getpid(), 1);
	parse_num(ft_atoi(av[1]), ft_strlen(av[2]));
	parse_ch(ft_atoi(av[1]), av[2]);
	return (0);
}
