/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:33:29 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 05:41:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	micro_a_to_b(t_node *a, t_node *b, t_node *msg)
{
	if (a->rlink->data > a->rlink->rlink->data)
	{
		if (a->rlink->rlink->data > a->llink->data)
		{
			s('a', a, b, msg);
			rr('a', a, b, msg);
		}
		else
		{
			if (a->rlink->data < a->llink->data)
				s('a', a, b, msg);
			else
				r('a', a, b, msg);
		}
	}
	else
	{
		if (a->rlink->data < a->llink->data)
		{
			rr('a', a, b, msg);
			s('a', a, b, msg);
		}
		else
			rr('a', a, b, msg);
	}
}

int		m_a_to_b_exit_chk(t_node *a, t_node *b, int n, t_node *msg)
{
	if (sorting_chk_a(a, n))
		return (1);
	if (n <= 2)
	{
		if (n == 2)
			s('a', a, b, msg);
		return (1);
	}
	return (0);
}

int		m_b_to_a_exit_chk(t_node *a, t_node *b, int n, t_node *msg)
{
	int i;

	i = -1;
	if (sorting_chk_b(b, n))
	{
		while (++i < n)
			p('a', a, b, msg);
		return (1);
	}
	if (n <= 2)
	{
		if (n == 2)
			s('b', a, b, msg);
		while (++i < n)
			p('a', a, b, msg);
		return (1);
	}
	return (0);
}

void	mini_a_to_b(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (m_a_to_b_exit_chk(a, b, n, msg))
		return ;
	mini_find_fivot(a, n, &d.f1);
	while (++d.i < n)
	{
		if (a->rlink->data <= d.f1)
		{
			p('b', a, b, msg);
			d.pb++;
		}
		else
		{
			r('a', a, b, msg);
			d.ra++;
		}
	}
	mini_a_to_b(a, b, d.ra, msg);
	mini_b_to_a(a, b, d.pb, msg);
}

void	mini_b_to_a(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (m_b_to_a_exit_chk(a, b, n, msg))
		return ;
	mini_find_fivot(b, n, &d.f1);
	while (++d.i < n)
	{
		if (b->rlink->data <= d.f1)
		{
			r('b', a, b, msg);
			d.rb++;
		}
		else
		{
			p('a', a, b, msg);
			d.pa++;
		}
	}
	mini_a_to_b(a, b, d.pa, msg);
	mini_b_to_a(a, b, d.rb, msg);
}
