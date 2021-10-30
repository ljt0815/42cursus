/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:22:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/31 04:34:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define PHILO_LEN 0
# define TTD 1
# define TTE 2
# define TTS 3
# define EAT_NUM 4

typedef struct s_dat	t_dat;
typedef struct s_pinfo {
	pthread_t		th;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	long long		last_eat;
	long long		last_sleep;
	int				idx;
	int				meal;
	t_dat			*d;
}	t_pinfo;

typedef struct s_dat {
	t_pinfo			*philo;
	pthread_mutex_t	*forks;
	int				args[5];
	int				err;
	int				die;
	long long		timestamp;
	pthread_mutex_t	print;
	pthread_t		monitor;
}	t_dat;

int			parse_arg(int ac, char *av[], t_dat *d);
void		start_meal_time(t_dat *d);
long long	get_timestamp(void);
#endif
