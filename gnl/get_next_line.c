/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:04 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/09 23:12:51 by jitlee           ###   ########.fr       */
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
	static char	*tmp;
	static int	is_not_first;
	char		reading_content[BUFFER_SIZE + 1];
	int			reading_length;
	int			idx;

	if (is_not_first != 1)
	{
		tmp = ft_strdup("");
		is_not_first = 1;
	}
	if ((idx = array_in_cr(tmp)) != -1)
	{
		*line = ft_strdup(ft_substr(tmp, 0, idx));
		tmp = ft_substr(tmp, idx + 1, BUFFER_SIZE);
		return (1);
	}
	while ((reading_length = read(fd, reading_content, BUFFER_SIZE)))
	{
		reading_content[reading_length] = 0;
		if ((idx = array_in_cr(reading_content)) != -1)
		{
			tmp = ft_strjoin(tmp, ft_substr(reading_content, 0, idx));
			*line = ft_strdup(tmp);
			tmp = ft_substr(reading_content, idx + 1, BUFFER_SIZE);
			return (1);
		}
		tmp = ft_strjoin(tmp, reading_content);
	}
	*line = "";
	return (0);
}
