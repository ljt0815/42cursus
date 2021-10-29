/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meal_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 06:07:44 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/30 07:16:16 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_dat		*d;
	long long	now;
	int			i;

	i = -1;
	d = (t_dat *)arg;
	while (d->die < 0)
	{
		i = -1;
		while (++i < d->args[0])
		{
			now = get_timestamp();
			if (now - d->philo[i].last_eat <= d->args[TTD])
				continue ;
			pthread_mutex_lock(&d->print);
			d->die = i;
			printf("%lld %d died\n", now - d->timestamp, i + 1);
			pthread_mutex_unlock(&d->print);
		}
	}
	return (0);
}

void	start_meal_time(t_dat *d)
{
	int	i;

	i = 0;
	if (pthread_create(&d->monitor, 0, &monitor, (void *)d))
		d->err = 1;
	pthread_join(d->monitor, 0);
	//while (i < d->args[PHILO_NUM])
	//	if (pthread_create
}
