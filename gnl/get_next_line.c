/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/07 01:03:23 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		not_in_cr_cycle(int fd, char *reading_content)
{
	char	*idx;
	int		rtn;
	int		read_cnt;

	rtn = 0;
	read_cnt = read(fd, reading_content, BUFFER_SIZE);
	reading_content[read_cnt] = 0;
	if ((idx = ft_strchr(reading_content, '\n')) != 0)
		rtn = idx - reading_content;
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*ttmp;
	char		*reading_content;
	int			idx;

	tmp = "";
	reading_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!(idx = not_in_cr_cycle(fd, reading_content)))
		tmp = ft_strjoin(tmp, reading_content);
	ttmp = ft_substr(reading_content, 0, idx);
	tmp = ft_strjoin(tmp, ttmp);
	*line = tmp;
	return (0);
}
