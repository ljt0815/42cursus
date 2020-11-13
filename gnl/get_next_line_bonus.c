/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/12 03:19:33 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		array_in_cr(char *reading_content)
{
	int		idx;

	idx = 0;
	while (reading_content[idx])
	{
		if (reading_content[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		make_ret(int reading_length, char **my_tmp, char **line)
{
	if (reading_length < 0)
		return (-1);
	if (*my_tmp[0] != 0)
	{
		*line = ft_strdup(*my_tmp);
		*my_tmp[0] = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		slice_buf(char **my_tmp, char *reading_content, int idx, char **line)
{
	if (BUFFER_SIZE == 1)
	{
		*line = ft_strdup(*my_tmp);
		ft_strlcpy(*my_tmp, reading_content + idx + 1, BUFFER_SIZE - idx);
		return (1);
	}
	*my_tmp = ft_strjoin(*my_tmp, reading_content, 0, idx);
	*line = ft_strdup(*my_tmp);
	ft_strlcpy(*my_tmp, reading_content + idx + 1, BUFFER_SIZE - idx);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*my_tmp[OPEN_MAX];
	char		reading_content[BUFFER_SIZE + 1];
	int			reading_length;
	int			idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if (my_tmp[fd] == 0)
		my_tmp[fd] = ft_strdup("");
	if ((idx = array_in_cr(my_tmp[fd])) != -1)
	{
		*line = ft_substr(my_tmp[fd], 0, idx);
		ft_strlcpy(my_tmp[fd], my_tmp[fd] + idx + 1, BUFFER_SIZE - idx);
		return (1);
	}
	while ((reading_length = read(fd, reading_content, BUFFER_SIZE)) > 0)
	{
		reading_content[reading_length] = 0;
		if ((idx = array_in_cr(reading_content)) != -1)
			return (slice_buf(&my_tmp[fd], reading_content, idx, line));
		my_tmp[fd] = ft_strjoin(my_tmp[fd], reading_content, 0, BUFFER_SIZE);
	}
	return (make_ret(reading_length, &my_tmp[fd], line));
}
