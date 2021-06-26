/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:47:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/26 05:11:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

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
