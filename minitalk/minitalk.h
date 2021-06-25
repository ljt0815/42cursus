/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:47:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/26 01:47:12 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
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
