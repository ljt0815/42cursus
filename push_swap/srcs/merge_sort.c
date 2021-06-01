/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:46:22 by marvin            #+#    #+#             */
/*   Updated: 2021/06/01 00:20:00 by marvin           ###   ########seoul.kr  */
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
		cnt++;
	}
	if (a->rlink->data > last)
	{
		while (cnt--)
		{
			r_rotate(a);
			swap(a);
		}
		rotate(a);
		return ;
	}
	while (a->rlink->data != last)
	{
		if (a->rlink->data > a->rlink->rlink->data)
			swap(a);
		else
			break;
		rotate(a);
		cnt++;
	}
	if (cnt < size / 2)
		while (cnt--)
			r_rotate(a);
	else
		while (cnt++ < size)
			rotate(a);
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
		rotate(a);
		return ;
	}
	while (a->rlink->data != last)
	{
		if (b->rlink->data < a->rlink->data)
		{
			push(a, b);
			break;
		}
		else
			rotate(a);	
		cnt++;	
	}
	if (cnt < size / 2)
		while (cnt--)
			r_rotate(a);
	else
		while (cnt++ < size + 1)
			rotate(a);
}

void	a_to_b(t_node *a, t_node *b, int n)
{
	printf("a_to_b%d\n",n);
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
				swap(a);
			push(b, a);
			push(b, a);
			if (a->rlink->data > a->rlink->rlink->data)
				swap(a);
		}			
		return ;
	}
	while (++(d.i) < n)
		push(b, a);
	a_to_b(a, b, d.next_n);
	//b_to_a(a, b, d.next_n);
}

void	b_to_a(t_node *a, t_node *b, int n)
{
	printf("b_to_a%d\n",n);
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
		}
		return ;
	}
	while (++(d.i) < n)
		push(b,a);
	a_to_b(a, b, d.next_n);
	//b_to_a(a, b, d.next_n);
}

void	merge_sort(t_node *a, t_node *b, int n)
{
	/*if (n % 2 == 0)
		a_to_b(a, b, n / 2);
	else
		a_to_b(a, b, (n / 2) + 1);*/
	n += 0;
	push(b, a);
	push(b, a);
	sorting_b(a, b);
	sorting_b(a, b);
	print_list(a);
	print_list(b);
}