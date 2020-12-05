/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:52 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/05 12:45:49 by jitlee           ###   ########.fr       */
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
# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_LL 3
# define LENGTH_L 4
# define LENGTH_J 5
# define LENGTH_Z 6
# define LENGTH_T 7
# define LENGTH_BIGL 8

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
int				ft_isflag(char *s, t_parse_dat *dat);
void			set_width(char *s, t_parse_dat *dat, int *i);
void			is_length(char *s, t_parse_dat *dat, int *i);
int				ft_isdigit(int c);
#endif
