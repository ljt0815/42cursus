/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:27:17 by marvin            #+#    #+#             */
/*   Updated: 2021/06/28 12:35:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_dat	g_dat;

void	usr1_handler(int signo, siginfo_t *info, void *context)
{
	int	i;

	i = -1;
	(void)context;
	(void)signo;
	ft_bzero(&g_dat, sizeof(g_dat));
	if (g_dat.client_num != 0)
		while (++i < g_dat.client_num)

	printf("signo : %d\n",signo);
	printf("pid : %d\n", info->si_pid);
}

int		main(void)
{
	struct sigaction	usrsig;

	write(1, "server pid : ", 13);
	ft_putnbr(getpid(), 1);
	usrsig.sa_sigaction = usr1_handler;
	usrsig.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &usrsig, 0);
	sigaction(SIGUSR2, &usrsig, 0);
	while(1)
		pause();
	return (0);
}
