/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:46:22 by marvin            #+#    #+#             */
/*   Updated: 2021/06/07 00:17:50 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sort(t_node *a, t_node *b, int asize, int bsize)
{
	int i;
	int n;

	i = -1;
	n = asize + bsize;
	while (++i < n)
	{
		if (asize == 0)
		{
			push(a, b);
			write(1, "pa\n", 3);
			rotate(a);
			write(1, "ra\n", 3);
			bsize--;
		}
		else if (bsize == 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
			asize--;
		}		
		else if (a->rlink->data < b->rlink->data)
		{
			rotate(a);
			write(1, "ra\n", 3);
			asize--;
		}
		else
		{
			push(a, b);
			write(1, "pa\n", 3);
			rotate(a);
			write(1, "ra\n", 3);
			bsize--;
		}
	}
	i = -1;
	while (++i < n)
	{
		r_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	b_sort(t_node *a, t_node *b, int asize, int bsize)
{
	int i;
	int n;

	i = -1;
	n = asize + bsize;
	while (++i < n)
	{
		if (bsize == 0)
		{
			push(b, a);
			write(1, "pb\n", 3);
			rotate(b);
			write(1, "rb\n", 3);
			asize--;
		}
		else if (asize == 0)
		{
			rotate(b);
			write(1, "rb\n", 3);
			bsize--;
		}		
		else if (b->rlink->data < a->rlink->data)
		{
			rotate(b);
			write(1, "rb\n", 3);
			bsize--;
		}
		else
		{
			push(b, a);
			write(1, "pb\n", 3);
			rotate(b);
			write(1, "rb\n", 3);
			asize--;
		}
	}
	i = -1;
	while (++i < n)
	{
		r_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	a_to_b(t_node *a, t_node *b, int n)
{
	//printf("a_to_b(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (n == 1)
		return ;
	while (++(d.i) < n / 2)
	{
		push(b, a);
		write(1, "pb\n", 3);
		d.pb++;
	}
	a_to_b(a, b, n - d.pb);
	b_to_a(a, b, d.pb);
	a_sort(a, b, n - d.pb, d.pb);
}

void	b_to_a(t_node *a, t_node *b, int n)
{
	//printf("b_to_a(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (n == 1)
		return ;
	while (++(d.i) < n / 2)
	{
		push(a,b);
		write(1, "pa\n", 3);
		d.pa++;
	}
	a_to_b(a, b, d.pa);
	b_to_a(a, b, n - d.pa);
	b_sort(a, b, d.pa, n - d.pa);
}

void	merge_sort(t_node *a, t_node *b, int n)
{
	a_to_b(a, b, n);
	print_list(a);
}