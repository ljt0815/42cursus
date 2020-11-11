/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/11 21:34:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		array_in_cr(char *reading_content)
{
	char	*idx;
	int		rtn;

	rtn = -1;
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
	static char	*my_tmp;
	static int	is_not_first;
	char		reading_content[BUFFER_SIZE + 1];
	int			reading_length;
	int			idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if ((is_not_first & 128) != 128)
	{
		my_tmp = ft_strdup("");
		is_not_first |= 128;
	}
	if ((idx = array_in_cr(my_tmp)) != -1)
	{
		free(*line);
		*line = ft_substr(my_tmp, 0, idx);
		ft_strlcpy(my_tmp, my_tmp + idx + 1, BUFFER_SIZE - idx);
		return (1);
	}
	while ((reading_length = read(fd, reading_content, BUFFER_SIZE)))
	{
		reading_content[reading_length] = 0;
		if ((idx = array_in_cr(reading_content)) != -1)
		{
			my_tmp = ft_strjoin(my_tmp, reading_content, 0, idx - 1);
			if ((is_not_first & 64) != 64)
				is_not_first |= 64;
			else
				free(*line);
			*line = ft_strdup(my_tmp);
			ft_strlcpy(my_tmp, reading_content + idx + 1, BUFFER_SIZE - idx);
			return (1);
		}
		my_tmp = ft_strjoin(my_tmp, reading_content, 0, BUFFER_SIZE);
	}
	free(*line);
	*line = ft_strdup("");
	return (0);
}
