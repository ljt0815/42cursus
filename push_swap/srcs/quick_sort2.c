/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:46:02 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 05:34:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		a_to_b_exit_chk(t_node *a, t_node *b, int n, t_node *msg)
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

void	a_to_b_func(t_node *a, t_node *b, t_dat *d, t_node *msg)
{
	while (++(d->i) < d->tmp)
	{
		if (a->rlink->data >= d->f2)
		{
			r('a', a, b, msg);
			d->ra++;
		}
		else
		{
			p('b', a, b, msg);
			d->pb++;
			if (b->rlink->data >= d->f1)
			{
				r('b', a, b, msg);
				d->rb++;
			}
		}
	}
}

int		b_to_a_exit_chk(t_node *a, t_node *b, int n, t_node *msg)
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

void	b_to_a_func(t_node *a, t_node *b, t_dat *d, t_node *msg)
{
	while (++(d->i) < d->tmp)
	{
		if (b->rlink->data < d->f1)
		{
			r('b', a, b, msg);
			d->rb++;
		}
		else
		{
			p('a', a, b, msg);
			d->pa++;
			if (a->rlink->data < d->f2)
			{
				r('a', a, b, msg);
				d->ra++;
			}
		}
	}
}
