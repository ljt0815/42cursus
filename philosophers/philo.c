/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:21:49 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/31 06:59:52 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_meal_time(t_dat *d)
{
	int	i;

	i = -1;
	pthread_join(d->monitor, 0);
	while (++i < d->args[PHILO_LEN])
		pthread_join(d->philo[i].th, 0);
	i = -1;
	while (++i < d->args[PHILO_LEN])
		pthread_mutex_destroy(&d->forks[i]);
	free(d->philo);
	free(d->forks);
}

int	make_philo_info(t_dat *d)
{
	int	i;

	i = -1;
	d->philo = malloc(sizeof(t_pinfo) * d->args[PHILO_LEN]);
	d->forks = malloc(sizeof(pthread_mutex_t) * d->args[PHILO_LEN]);
	if (d->philo == 0 || d->forks == 0)
		return (-1);
	d->timestamp = get_timestamp();
	if (d->args[EAT_NUM] == 0)
		d->infinite = 1;
	while (++i < d->args[PHILO_LEN])
	{
		memset(&d->philo[i], 0, sizeof(t_pinfo));
		d->philo[i].idx = i;
		d->philo[i].last_eat = d->timestamp;
		d->philo[i].d = d;
	}
	return (0);
}

int	put_fork_table(t_dat *d)
{
	int	i;

	i = -1;
	while (++i < d->args[PHILO_LEN])
	{
		if (pthread_mutex_init(&d->forks[i], 0))
			return (-1);
		d->philo[i].l_hand = &d->forks[i];
		d->philo[i].r_hand = &d->forks[(i + 1) % d->args[PHILO_LEN]];
	}
	if (pthread_mutex_init(&d->print, 0))
		return (-1);
	return (0);
}

int	init_philo(int ac, char *av[], t_dat *d)
{
	if (parse_arg(ac, av, d) == -1)
	{
		printf("arguments not valid\n");
		return (-1);
	}
	else if (make_philo_info(d) == -1)
		printf("make philo error\n");
	else if (put_fork_table(d) == -1)
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
	int		flag;

	memset(&d, 0, sizeof(t_dat));
	if (!(ac == 5 || ac == 6))
	{
		printf("argument error!\n");
		return (0);
	}
	flag = init_philo(ac, av, &d);
	if (flag == 1)
		start_meal_time(&d);
	if (flag != -1)
		end_meal_time(&d);
	return (0);
}
