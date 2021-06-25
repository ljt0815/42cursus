/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:27:57 by marvin            #+#    #+#             */
/*   Updated: 2021/06/25 16:24:08 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <unistd.h>

typedef struct {
	char	*buf;
	int		len;
}	t_buf;

typedef struct {
	t_buf	buf;
	char	ch;
	int		n;
}	t_dat;
#endif