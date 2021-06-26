/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:27:17 by marvin            #+#    #+#             */
/*   Updated: 2021/06/26 05:17:26 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	usr1_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	printf("signo : %d\n",signo);
	printf("pid : %d\n", info->si_pid);
}

void	usr2_handler(int signo)
{
	printf("signo : %d\n",signo);
}

int		main(void)
{
	struct sigaction usrsig;

	printf("server pid : %d\n", getpid());
	usrsig.sa_sigaction = usr1_handler;
	usrsig.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &usrsig, 0);
	while(1)
		pause();
	return (0);
}
