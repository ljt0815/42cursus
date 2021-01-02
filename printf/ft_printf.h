/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:52 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 14:52:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAG_MINUS 1
# define FLAG_ZERO 2
# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_LL 3
# define LENGTH_L 4
# define LENGTH_J 5
# define LENGTH_Z 6
# define LENGTH_T 7
# define LENGTH_BIGL 8
# define SPECIFIER_C 1
# define SPECIFIER_S 2
# define SPECIFIER_P 3
# define SPECIFIER_D 4
# define SPECIFIER_I 5
# define SPECIFIER_U 6
# define SPECIFIER_X 7
# define SPECIFIER_BIGX 8
# define SPECIFIER_PER 9

typedef struct {
	int	flag;
	int	width;
	int	dot;
	int	precision;
	int	length;
	int	specifier;
	int	read_size;
}		t_parse_dat;
int		ft_printf(const char *s, ...);
int		parse_str(char *s, va_list *ap, t_parse_dat *dat, int *rtn);
void	ft_bzero(void *s, size_t n);
int		ft_isflag(char *s, t_parse_dat *dat);
void	set_width(char *s, t_parse_dat *dat, int *i);
void	is_length(char *s, t_parse_dat *dat, int *i);
int		ft_isdigit(int c);
void	is_specifier(char *s, t_parse_dat *dat, int *i);
void	print_dat(t_parse_dat *dat, va_list *ap, int *rtn);
void	print_ch(t_parse_dat *dat, va_list *ap, int *rtn);
void	print_str(t_parse_dat *dat, va_list *ap, int *rtn);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	print_adr(t_parse_dat *dat, va_list *ap, int *rtn);
void	print_int(t_parse_dat *dat, va_list *ap, int *rtn);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_itox(unsigned int n);
char	*ft_itobigx(unsigned int n);
int		num_len(long long n);
int		hex_len(long long n);
void	proc_else(t_parse_dat *dat, char *tmp, char *result, int len);
void	print_else(char *result, char *tmp, int *rtn, t_parse_dat *dat);
void	fill_front(char *tmp, char *num, t_parse_dat *dat);
void	sub_fill(char *result, char *tmp, int num_len, t_parse_dat *dat);
void	fill_back(char *result, char *tmp, char *num, t_parse_dat *dat);
char	*alloc_arr(char *num, t_parse_dat *dat);
void	print_hex(t_parse_dat *dat, va_list *ap, int *rtn);
void	print_per(t_parse_dat *dat, int *rtn);
#endif
