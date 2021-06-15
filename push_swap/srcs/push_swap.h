/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:40:25 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 10:26:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft.h"
# include "listnode.h"
# include <unistd.h>
# include <stdlib.h>

# define RA 1
# define RB 2
# define RR 3
# define RRA 4
# define RRB 5
# define RRR 6
# define PA 7
# define PB 8
# define SA 9
# define SB 10
# define SS 11

typedef struct {
	int		i;
	int		tmp;
	int		f1;
	int		f2;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
}			t_dat;

void		swap(t_node *n);
void		push(t_node *n1, t_node *n2);
void		r_rotate(t_node *n);
void		rotate(t_node *n);
void		free_node(t_node *n);
void		quick_sort(t_node *a, t_node *b, int n);
void		a_to_b(t_node *a, t_node *b, int n, t_node *msg);
void		b_to_a(t_node *a, t_node *b, int n, t_node *msg);
void		r(char c, t_node *a, t_node *b, t_node *msg);
void		rr(char c, t_node *a, t_node *b, t_node *msg);
void		p(char c, t_node *a, t_node *b, t_node *msg);
void		s(char c, t_node *a, t_node *b, t_node *msg);
void		mini_a_to_b(t_node *a, t_node *b, int n, t_node *msg);
void		mini_b_to_a(t_node *a, t_node *b, int n, t_node *msg);
void		print_msg(t_node *msg);
void		optimize_msg(t_node *msg);
void		err_msg(void);
void		bubble_sort(int *arr, int n);
int			sorting_chk_a(t_node *node, int n);
int			sorting_chk_b(t_node *node, int n);
void		find_fivot(t_node *node, int n, int *f1, int *f2);
void		mini_find_fivot(t_node *node, int n, int *f);
void		rrx(t_node *a, t_node *b, t_dat *d, t_node *msg);
void		micro_a_to_b(t_node *a, t_node *b, t_node *msg);
void		mini_a_to_b(t_node *a, t_node *b, int n, t_node *msg);
void		mini_b_to_a(t_node *a, t_node *b, int n, t_node *msg);
int			a_to_b_exit_chk(t_node *a, t_node *b, int n, t_node *msg);
void		a_to_b_func(t_node *a, t_node *b, t_dat *d, t_node *msg);
int			b_to_a_exit_chk(t_node *a, t_node *b, int n, t_node *msg);
void		b_to_a_func(t_node *a, t_node *b, t_dat *d, t_node *msg);
void		free_split(int flag, char **av);
#endif
