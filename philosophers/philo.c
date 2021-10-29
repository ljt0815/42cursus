/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:21:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/30 04:47:29 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(int ac, char *av[], t_dat *d)
{
	parse_arg(ac, av, d);
	return (0);
}

int	main(int ac, char *av[])
{
	t_dat	d;
	memset(&d, 0, sizeof(t_dat));
	if (!(ac == 5 || ac == 6))
		printf("argument error!\n");
	else if (!init_philo(ac, av, &d))
		return (0);
	return (0);
}
