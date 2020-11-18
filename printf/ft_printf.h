/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:52 by jitlee            #+#    #+#             */
/*   Updated: 2020/11/19 04:40:45 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAG_MINUS 1
# define FLAG_ZERO 2
# define FLAG_BLANK 4
# define FLAG_PLUS 8

typedef struct	s_parse_dat{
	int	flag;
	int	width;
	int	precision;
	int	length;
	int	specifier;
}				t_parse_dat;
int				ft_printf(const char *s, ...);
int				parse_str(char *s, va_list *ap, t_parse_dat *dat);
void			ft_bzero(void *s, size_t n);
#endif
