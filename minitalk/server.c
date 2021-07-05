/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:27:17 by marvin            #+#    #+#             */
/*   Updated: 2021/07/05 12:46:33 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_dat	g_dat;

void	usr_handler(int signo, siginfo_t *info, void *context)
{
	int	i;
	//int j;//
	
	(void)context;
	//j = -1;//
	i = -1;

	while (++i < g_dat.client_num)
		if (g_dat.buf[i].pid == info->si_pid)
			break ;
	if (i == g_dat.client_num)
	{
		g_dat.buf[i].pid = info->si_pid;
		g_dat.client_num += 1;
	}
	//printf("g_dat.client_num : %d\n", g_dat.client_num);//
	//while (++j < g_dat.client_num)
	//	printf("pid[%d]: %d\n", j, g_dat.buf[j].pid);//
	if (g_dat.buf[i].n < 32)
	{
		g_dat.buf[i].len <<= 1;
		if (signo == SIGUSR2)
			g_dat.buf[i].len += 1;
	}
	else
	{
		if (g_dat.buf[i].n == 32)
			g_dat.buf[i].buf = malloc(g_dat.buf[i].len + 1);
		if (g_dat.buf[i].n > 32 && g_dat.buf[i].n % 8 == 0)
		{
			g_dat.buf[i].buf[(g_dat.buf[i].n / 8) - 5] = g_dat.buf[i].ch;
			g_dat.buf[i].ch = 0;
		}
		g_dat.buf[i].ch <<= 1;
		 if (signo == SIGUSR2)
			 g_dat.buf[i].ch += 1;
	}
	g_dat.buf[i].n += 1;
	if ((g_dat.buf[i].n / 8) - 4 == g_dat.buf[i].len)
	{
		g_dat.buf[i].buf[(g_dat.buf[i].n / 8) - 5] = g_dat.buf[i].ch;
		write(1, g_dat.buf[i].buf, g_dat.buf[i].len);
		write(1, "\n", 1);
		free(g_dat.buf[i].buf);
		if (i == g_dat.client_num - 1)
			ft_bzero(&g_dat.buf[i], sizeof(t_buf));
		else
		{
			ft_memcpy(&g_dat.buf[i], &g_dat.buf[g_dat.client_num - 1], sizeof(t_buf));
			ft_bzero(&g_dat.buf[g_dat.client_num - 1], sizeof(t_buf));
		}
		g_dat.client_num -= 1;
	}
}

int		main(void)
{
	struct sigaction	usrsig;

	write(1, "server pid : ", 13);
	ft_putnbr(getpid(), 1);
	ft_bzero(&g_dat, sizeof(g_dat));
	usrsig.sa_sigaction = usr_handler;
	usrsig.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &usrsig, 0);
	sigaction(SIGUSR2, &usrsig, 0);
	while(1)
		pause();
	return (0);
}
