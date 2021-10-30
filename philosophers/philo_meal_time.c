/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meal_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 06:07:44 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/31 06:55:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_num_cnt(t_dat *d)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < d->args[PHILO_LEN])
		if (d->philo[i].meal >= d->args[EAT_NUM])
			cnt++;
	return (cnt);
}

void	*monitor(void *arg)
{
	t_dat		*d;
	long long	now;

	d = (t_dat *)arg;
	while (d->die < 0)
	{
		d->i = -1;
		while (++d->i < d->args[0])
		{
			now = get_timestamp();
			if (!d->infinite && eat_num_cnt(d) == d->args[PHILO_LEN])
			{
				d->end = 1;
				return (0);
			}
			if (now - d->philo[d->i].last_eat <= d->args[TTD])
				continue ;
			pthread_mutex_lock(&d->print);
			d->die = d->i;
			printf("%lld %d died\n", now - d->timestamp, d->i + 1);
			pthread_mutex_unlock(&d->print);
			return (0);
		}
	}
	return (0);
}

void	print_state(t_pinfo *philo, t_dat *d, char *str)
{
	long long	now;

	pthread_mutex_lock(&d->print);
	now = get_timestamp();
	if (d->die != -1 || d->end == 1)
	{
		pthread_mutex_unlock(&d->print);
		return ;
	}
	printf("%lld %d%s", now - d->timestamp, philo->idx + 1, str);
	pthread_mutex_unlock(&d->print);
}

void	my_usleep(int ms)
{
	long long	goal_time;
	long long	usleep_time;

	goal_time = ms + get_timestamp();
	while (goal_time > get_timestamp())
	{
		usleep_time = (goal_time - get_timestamp()) / 2;
		if ((long long)100 > usleep_time)
			usleep(100);
		else
			usleep(usleep_time);
	}
}

void	pick_up_fork(t_pinfo *philo, t_dat *d)
{
	if (philo->idx % 2 == 0)
		pthread_mutex_lock(philo->l_hand);
	else
		pthread_mutex_lock(philo->r_hand);
	print_state(philo, d, " has taken fork\n");
	if (philo->l_hand == philo->r_hand)
	{
		my_usleep(d->args[TTD] + 100);
		pthread_mutex_unlock(philo->l_hand);
		return ;
	}
	if (philo->idx % 2 == 0)
		pthread_mutex_lock(philo->r_hand);
	else
		pthread_mutex_lock(philo->l_hand);
	print_state(philo, d, " has taken fork\n");
	(philo->meal)++;
	print_state(philo, d, " is eating\n");
	philo->last_eat = get_timestamp();
	my_usleep(d->args[TTE]);
	pthread_mutex_unlock(philo->l_hand);
	pthread_mutex_unlock(philo->r_hand);
}

void	go_to_sleep(t_pinfo *philo, t_dat *d)
{
	if (d->die != -1)
		return ;
	print_state(philo, d, " is sleeping\n");
	my_usleep(d->args[TTS]);
	print_state(philo, d, " is thinking\n");
}

void	*simulator(void *arg)
{
	t_pinfo	*philo;
	t_dat	*d;

	philo = (t_pinfo *)arg;
	d = philo->d;
	while (d->die == -1 && d->end == 0)
	{
		pick_up_fork(philo, d);
		go_to_sleep(philo, d);
	}
	return (0);
}

void	start_meal_time(t_dat *d)
{
	int	i;

	i = -1;
	if (pthread_create(&d->monitor, 0, &monitor, (void *)d))
		d->err = 1;
	while (++i < d->args[PHILO_LEN])
		if (i % 2 == 0)
			if (pthread_create(&d->philo[i].th, 0, \
						&simulator, (void *)&d->philo[i]))
				d->err = 1;
	i = 0;
	while (++i < d->args[PHILO_LEN])
		if (i % 2 == 1)
			if (pthread_create(&d->philo[i].th, 0, \
						&simulator, (void *)&d->philo[i]))
				d->err = 1;
	if (d->err == 1)
		printf("Thread Create Fail!\n");
}
