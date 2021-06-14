/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 05:39:09 by marvin            #+#    #+#             */
/*   Updated: 2021/06/15 05:41:05 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (a_to_b_exit_chk(a, b, n, msg))
		return ;
	find_fivot(a, n, &d.f1, &d.f2);
	d.tmp = n;
	a_to_b_func(a, b, &d, msg);
	rrx(a, b, &d, msg);
	a_to_b(a, b, d.ra, msg);
	b_to_a(a, b, d.rb, msg);
	b_to_a(a, b, d.pb - d.rb, msg);
}

void	b_to_a(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (b_to_a_exit_chk(a, b, n, msg))
		return ;
	find_fivot(b, n, &d.f1, &d.f2);
	d.tmp = n;
	b_to_a_func(a, b, &d, msg);
	a_to_b(a, b, d.pa - d.ra, msg);
	rrx(a, b, &d, msg);
	a_to_b(a, b, d.ra, msg);
	b_to_a(a, b, d.rb, msg);
}

void	quick_sort(t_node *a, t_node *b, int n)
{
	t_node	msg;

	init_node(&msg);
	if (sorting_chk_a(a, n))
		return ;
	else if (n == 3)
		micro_a_to_b(a, b, &msg);
	else if (n <= 8)
		mini_a_to_b(a, b, n, &msg);
	else
		a_to_b(a, b, n, &msg);
	optimize_msg(&msg);
	print_msg(&msg);
}
