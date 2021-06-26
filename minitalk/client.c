/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:45:30 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/26 11:06:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	parse_num(int pid, char *s)
{
	int i;
	int	j;

	i = -1;
	while (s[++i] != 0)
	{
		j = 128;
		while (j > 0)
		{
			if (s[i] & j == 1)
			{
				if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
				{
					write(2, "Error\n", 6);
					return (0);
				}
			}
			j >>= 1;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	printf("%d\n",getpid());
	return (0);
}
