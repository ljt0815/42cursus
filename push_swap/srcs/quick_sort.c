/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 05:39:09 by marvin            #+#    #+#             */
/*   Updated: 2021/06/12 12:38:11 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int i;
	int j;
	int tmp;
	
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void	find_fivot(t_node *node, int n, int *f1, int *f2)
{
	//t_node	*head;
	int		*arr;
	int		i;

	i = -1;
	//head = node;
	arr = malloc(sizeof(int) * (n + 1));
	while (++i < n)
	{
		node = node->rlink;
		arr[i] = node->data;
	}
	/*printf("before ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	puts("");*/
	bubble_sort(arr, n);
	/*
	printf("after ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);*/
	if (n % 3 == 2)
	{
		*f1 = arr[(n / 3)];
		*f2 = arr[((n / 3) * 2) + 1];
	}
	else
	{
		*f1 = arr[(n / 3)];
		*f2 = arr[(n / 3) * 2];
	}
	free(arr);
}

void	rrx(t_node *a, t_node *b, t_dat *d)
{
	int flag;

	flag = 0;
	d->tmp = d->ra;
	if (d->rb < d->tmp)
	{
		d->tmp = d->rb;
		flag = 1;
	}
	d->i = -1;
	while (++d->i < d->tmp)
		rr('r', a, b);
	d->i = -1;
	if (flag == 0)
		while (++d->i < d->rb - d->ra)
			rr('b', a, b);
	else
		while (++d->i < d->ra - d->rb)
			rr('a', a, b);
}

int		sorting_chk_a(t_node *node, int n)
{
	int		max;
	int		i;
	
	i = 0;
	node = node->rlink;
	max = node->data;
	while (++i < n)
	{
		node = node->rlink;
		if (max < node->data)
			max = node->data;
		else
			break;
	}
	if (i == n)
		return 1;
	return 0;
}

int		sorting_chk_b(t_node *node, int n)
{
	int		min;
	int		i;
	
	i = 0;
	node = node->rlink;
	min = node->data;
	while (++i < n)
	{
		node = node->rlink;
		if (min > node->data)
			min = node->data;
		else
			break;
	}
	if (i == n)
		return 1;
	return 0;
}

void	a_to_b(t_node *a, t_node *b, int n)
{
	//printf("a_to_b(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk_a(a, n))
		return ;
	if (n == 2)
	{
		s('a', a, b);
		return ;
	}
	if (n <= 1)
		return ;
	find_fivot(a, n, &d.f1, &d.f2);
	//printf("fivot : %d, %d\n", d.f1, d.f2);
	while (++(d.i) < n)
	{
		if (a->rlink->data >= d.f2)
		{
			r('a', a, b);
			d.ra++;
		}
		else
		{
			p('b', a, b);
			d.pb++;
			if (b->rlink->data >= d.f1)
			{
				r('b', a, b);
				d.rb++;
			}
		}
	}
	rrx(a, b, &d);
	a_to_b(a, b, d.ra);
	b_to_a(a, b, d.rb);
	b_to_a(a, b, d.pb - d.rb);
}

void	b_to_a(t_node *a, t_node *b, int n)
{
	//printf("b_to_a(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk_b(b, n))
	{
		while (++d.i < n)
			p('a', a, b);
		return ;
	}
	if (n == 2)
	{
		s('b', a, b);
		p('a', a, b);
		p('a', a, b);
		return ;
	}
	if (n == 1)
	{
		p('a', a, b);
		return ;
	}
	if (n <= 0)
		return;
	find_fivot(b, n, &d.f1, &d.f2);
	//printf("fivot : %d, %d\n", d.f1, d.f2);
	while (++(d.i) < n)
	{
		if (b->rlink->data < d.f1)
		{
			r('b', a, b);
			d.rb++;
		}
		else
		{
			p('a', a, b);
			d.pa++;
			if (a->rlink->data < d.f2)
			{
				r('a', a, b);
				d.ra++;
			}
		}
	}
	a_to_b(a, b, d.pa - d.ra);
	rrx(a, b, &d);
	a_to_b(a, b, d.ra);
	b_to_a(a, b, d.rb);
}

void	quick_sort(t_node *a, t_node *b, int n)
{
	a_to_b(a, b, n);
	print_list(a);
	print_list(b);
}
