/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:40:25 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/09 04:03:34 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft.h"
# include "listnode.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct {
	int		i;
    int     tmp;
    int     f1;
    int     f2;
    int     pa;
    int     pb;
    int     ra;
    int     rb;
}   t_dat;

void	swap(t_node *n);
void	push(t_node *n1, t_node *n2);
void	r_rotate(t_node *n);
void	rotate(t_node *n);
void	merge_sort(t_node *a, t_node *b, int n);
void	quick_sort(t_node *a, t_node *b, int n);
void	a_to_b(t_node *a, t_node *b, int n);
void	b_to_a(t_node *a, t_node *b, int n);
#endif
