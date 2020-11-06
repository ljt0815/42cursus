/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/06 23:38:44 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		not_in_cr_cycle(int fd, char *reading_content)
{
	char	*idx;
	int		rtn;

	rtn = 0;
	read(fd, reading_content, BUFFER_SIZE);
	if ((idx = ft_strchr(reading_content, '\n')) != 0)
		rtn = idx - reading_content;
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*reading_content;

	tmp = "";
	reading_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!not_in_cr_cycle(fd, reading_content))
		tmp = ft_strjoin(tmp, reading_content);
	*line = tmp;
	return (0);
}
