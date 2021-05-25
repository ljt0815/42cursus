/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:07:22 by marvin            #+#    #+#             */
/*   Updated: 2021/05/25 06:16:35 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fivot_set(int *fivot1, int *fivot2)
{
	int tmp;
	
	if (*fivot1 > *fivot2)
	{
		tmp = *fivot1;
		*fivot1 = *fivot2;
		*fivot2 = tmp;
	}
}

void	rrr(t_node *a, t_node *b, t_dat *d, int tmp)
{
	d->i = -1;
	d->tmp = d->ra;
	if (d->tmp > d->rb)
	{
		d->tmp = d->rb;
		tmp = 1;
	}
	while (++(d->i) < d->tmp)
	{
		r_rotate(a);
		r_rotate(b);
		write(1, "rrr\n", 4);
	}
	if (tmp == 1)
		while ((d->tmp)++ - d->ra)
		{
			r_rotate(a);
			write(1, "rra\n", 3);
		}
	else
		while ((d->tmp)++ - d->rb)
		{
			r_rotate(b);
			write(1, "rrb\n", 3);
		}
}

void	a_to_b2(t_node *a, t_node *b, t_dat *d)
{
	if (a->rlink->data > d->fivot2)
	{
		rotate(a);
		write(1, "ra\n", 3);
		(d->ra)++;
	}
	else
	{
		push(b, a);
		write(1, "pb\n", 3);
		(d->pb)++;
		if (b->rlink->data > d->fivot1)
		{
			rotate(b);
			write(1, "rb\n", 3);
			(d->rb)++;
		}
	}
}

void	b_to_a2(t_node *a, t_node *b, t_dat *d)
{
	if (b->rlink->data > d->fivot2)
	{
		rotate(b);
		write(1, "rb\n", 3);
		(d->rb)++;
	}
	else
	{
		push(a, b);
		write(1, "pa\n", 3);
		(d->pa)++;
		if (a->rlink->data > d->fivot1)
		{
			rotate(a);
			write(1, "ra\n", 3);
			(d->ra)++;
		}
	}
}

void	b_to_a(t_node *a, t_node *b, int n)
{
	t_dat	d;
	
	if (n < 3)
	{
		d.i = -1;
		while (++(d.i) <= n)
		{
			if (b->rlink->data < b->rlink->rlink->data)
				swap(b);
			push(a, b);
			write(1, "pa\n", 3);
		}
		return ;
	}
	ft_bzero(&d, sizeof(d));
	d.fivot1 = b->rlink->data;
	d.fivot2 = b->rlink->rlink->data;
	fivot_set(&(d.fivot1), &(d.fivot2));
	d.i = -1;
	while (++(d.i) < n)
		b_to_a2(a, b, &d);
	rrr(a, b, &d, 0);
	a_to_b(a, b, d.rb);
	b_to_a(a, b, d.ra);
}

void	a_to_b(t_node *a, t_node *b, int n)
{
	t_dat	d;
	
	if (n < 3)
	{
		if (a->rlink->data > a->rlink->rlink->data)
			swap(b);	
		return ;
	}
	ft_bzero(&d, sizeof(d));
	d.fivot1 = a->rlink->data;
	d.fivot2 = a->rlink->rlink->data;
	fivot_set(&(d.fivot1), &(d.fivot2));
	d.i = -1;
	while (++(d.i) < n)
		a_to_b2(a, b, &d);
	rrr(a, b, &d, 0);
	a_to_b(a, b, d.ra);
	b_to_a(a, b, d.rb);
	b_to_a(a, b, d.pb - d.rb);
}

void	quick_sort(t_node *a, t_node *b, int ac)
{
	a_to_b(a, b, ac - 1);
	print_list(a);
	print_list(b);
}