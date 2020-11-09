/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/09 16:50:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = -1;
	while (src[len])
		len++;
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	while (src[++i])
		result[i] = src[i];
	result[i] = 0;
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	static int	flag;
	char		*reading_content;
	int			idx;

	if (flag != 1)
	{
		tmp = "";
		flag = 1;
	}
	reading_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!(idx = not_in_cr_cycle(fd, reading_content)))
		tmp = ft_strjoin(tmp, reading_content);
	tmp = ft_strjoin(tmp, ft_substr(reading_content, 0, idx));
	*line = ft_strdup(tmp);
	tmp = ft_substr(reading_content, idx + 1, BUFFER_SIZE);
	return (0);
}
