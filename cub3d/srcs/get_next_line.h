/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:17:17 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/03 02:44:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
size_t	cft_strlen(const char *s);
size_t	cft_strlcpy(char *dest, const char *src, size_t size);
size_t	cft_strlcat(char *dest, const char *src, size_t size);
char	*cft_strdup(const char *src);
char	*cft_strjoin(char *s1, char *s2, int s2_start, int s2_end);
char	*cft_substr(char *s, unsigned int start, size_t len);
#endif
