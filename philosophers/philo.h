/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:22:26 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/30 06:09:06 by jitlee           ###   ########.fr       */
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

# define PHILO_NUM 0
# define TTD 1
# define TTE 2
# define TTS 3
# define EAT_NUM 4

typedef struct	s_pinfo {
	pthread_t	th;
	long long	last_eat;
}	t_pinfo;

typedef struct	s_dat {
	t_pinfo		*philo;
	int			args[5];
	int			err;
	long long	timestamp;
	pthread_t	monitor;
}	t_dat;

int	parse_arg(int ac, char *av[], t_dat *d);
#endif