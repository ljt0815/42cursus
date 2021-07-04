/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:47:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/07/05 05:17:38 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_CLIENT 100

typedef struct {
	char	*buf;
	char	ch;
	int		len;
	int		pid;
	int		n;
}	t_buf;

typedef struct {
	t_buf	buf[MAX_CLIENT];
	int		client_num;
}	t_dat;

extern	t_dat g_dat;
void	send_signal(int pid, int signo);
void	ft_putnbr(int num, int isnewline);
#endif
