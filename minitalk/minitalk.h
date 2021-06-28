/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:47:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/28 12:33:20 by jitlee           ###   ########.fr       */
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
	int		len;
}	t_buf;

typedef struct {
	t_buf	buf[MAX_CLIENT];
	char	ch;
	int		client_num;
	int		all_recived_n;
	int		n;
}	t_dat;

extern	g_dat;
void	send_signal(int pid, int signo);
void	ft_putnbr(int num, int isnewline);
#endif
