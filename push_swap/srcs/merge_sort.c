/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:46:22 by marvin            #+#    #+#             */
/*   Updated: 2021/06/01 01:46:48 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_node(t_node *head)
{
	int		cnt;

	head = head->rlink;
	cnt = 0;
	while (head->data != -2147483648)
	{
		head = head->rlink;
		cnt++;
	}
	return (cnt);
}

void	sorting_a(t_node *a, int n)
{
	int		cnt;
	int		last;
	int		size;

	cnt = 0;
	last = a->llink->data;
	size = count_node(a);
	while (n--)
	{
		rotate(a);
		write(1, "ra\n", 3);
		cnt++;
	}
	if (a->rlink->data > last)
	{
		while (cnt--)
		{
			r_rotate(a);
			write(1, "rra\n", 4);
			swap(a);
			write(1, "sa\n", 3);
		}
		rotate(a);
		write(1, "ra\n", 3);
		return ;
	}
	while (a->rlink->data != last)
	{
		if (a->rlink->data > a->rlink->rlink->data)
		{
			swap(a);
			write(1, "sa\n", 3);
		}
		else
			break;
		rotate(a);
		write(1, "ra\n", 3);
		cnt++;
	}
	if (cnt < size / 2)
		while (cnt--)
		{
			r_rotate(a);
			write(1, "rra\n", 4);
		}
	else
		while (cnt++ < size)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
}

void	sorting_b(t_node *a, t_node *b)
{
	int		last;
	int		size;
	int		cnt;

	cnt = 0;
	last = a->llink->data;
	size = count_node(a);
	if (b->rlink->data > last)
	{
		push(a, b);
		write(1, "pa\n", 3);
		rotate(a);
		write(1, "ra\n", 3);
		return ;
	}
	if (b->rlink->data > a->llink->llink->data)
	{
		r_rotate(a);
		write(1, "rra\n", 4);
		push(a, b);
		write(1, "pa\n", 3);
		rotate(a);
		write(1, "ra\n", 3);
		rotate(a);
		write(1, "ra\n", 3);
		return ;
	}
	while (a->rlink->data != last)
	{
		if (b->rlink->data < a->rlink->data)
		{
			push(a, b);
			write(1, "pa\n", 3);
			break;
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		cnt++;	
	}
	if (cnt < size / 2)
		while (cnt--)
		{
			r_rotate(a);
			write(1, "rra\n", 4);
		}
	else
		while (cnt++ < size + 1)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
}

void	a_to_b(t_node *a, t_node *b, int n)
{
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (n % 2 == 0)
		d.next_n = (n / 2);
	else
		d.next_n = (n / 2) + 1;
	if (n <= 2)
	{
		if (n == 2)
		{
			if (a->rlink->data > a->rlink->rlink->data)
			{
				swap(a);
				write(1, "sa\n", 3);
			}
			push(b, a);
			write(1, "pb\n", 3);
			push(b, a);
			write(1, "pb\n", 3);
			if (a->rlink->data > a->rlink->rlink->data)
			{
				swap(a);
				write(1, "sa\n", 3);
			}
		}
		return ;
	}
	while (++(d.i) < n)
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
	a_to_b(a, b, d.next_n);
	b_to_a(a, b, d.next_n);
}

void	b_to_a(t_node *a, t_node *b, int n)
{
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (n % 2 == 0)
		d.next_n = (n / 2);
	else
		d.next_n = (n / 2) + 1;
	if (n <= 2)
	{
		if (n == 2)
		{
			sorting_a(a, 1);
			sorting_a(a, 0);
			sorting_b(a, b);
			sorting_b(a, b);
		}
		return ;
	}
	while (++(d.i) < n)
	{
		push(a,b);
		write(1, "pa\n", 3);
	}
	a_to_b(a, b, d.next_n);
	b_to_a(a, b, d.next_n);
}

void	merge_sort(t_node *a, t_node *b, int n)
{
	if (n % 2 == 0)
		a_to_b(a, b, n / 2);
	else
		a_to_b(a, b, (n / 2) + 1);
	if (n % 2 == 0)
		b_to_a(a, b, n / 2);
	else
		b_to_a(a, b, (n / 2) + 1);
}