/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:21:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/30 18:51:23 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timestamp(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, 0);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

void	pthread_all_join(t_dat *d)
{
	int	i;

	i = -1;
	pthread_join(d->monitor, 0);
	while (++i < d->args[PHILO_NUM])
		pthread_join(d->philo[i].th, 0);
	free(d->philo);
}

int	make_philo_info(t_dat *d)
{
	int	i;

	i = -1;
	d->philo = malloc(sizeof(t_pinfo) * d->args[PHILO_NUM]);
	if (d->philo == 0)
		return (-1);
	d->timestamp = get_timestamp();
	while (++i < d->args[PHILO_NUM])
	{
		d->philo[i].idx = i;
		d->philo[i].last_eat = d->timestamp;
	}
	return (0);
}

int	philo_give_fork

int	init_philo(int ac, char *av[], t_dat *d)
{
	if (parse_arg(ac, av, d) == -1)
		printf("arguments not valid\n");
	else if (make_philo_info(d) == -1)
		printf("make philo error\n");
	else if (philo_give_fork(d) == -1)
		printf("mutex init error\n");
	else
	{
		d->die = -1;
		return (1);
	}
	
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
	start_meal_time(&d);
	pthread_all_join(&d);
	return (0);
}
