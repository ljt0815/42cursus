/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 06:59:34 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/31 07:49:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_print(char *msg)
{
	int	len;

	len = -1;
	while (msg[++len])
		;
	write(2, msg, len);
}

long long	get_timestamp(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, 0);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
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
