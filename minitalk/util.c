/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:35:29 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/28 11:51:33 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int signo)
{	
	if (kill(pid, signo) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	usleep(100);
}

void	ft_putnbr(int num, int isnewline)
{
	char	*buf;

	buf = ft_itoa(num);
	write(1, buf, ft_strlen(buf));
	if (isnewline)
		write(1, "\n", 1);
	free(buf);
}
