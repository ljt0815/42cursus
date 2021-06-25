/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:27:17 by marvin            #+#    #+#             */
/*   Updated: 2021/06/18 10:46:54 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	usr1_handler(int signo)
{
	printf("signo : %d\n",signo);
}

void	usr2_handler(int signo)
{
	printf("signo : %d\n",signo);
}

int		main(void)
{
	signal(SIGUSR1, usr1_handler);
	signal(SIGUSR2, usr2_handler);
	while(1)
		pause();
	return (0);
}