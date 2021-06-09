/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 05:39:09 by marvin            #+#    #+#             */
/*   Updated: 2021/06/09 03:27:58 by marvin           ###   ########seoul.kr  */
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

int		sorting_chk(t_node *node, int n)
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

void	a_to_b(t_node *a, t_node *b, int n, int *debug)
{
	//printf("a_to_b(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk(a, n))
		return ;
	if (n == 2)
	{
		if (a->rlink->data > a->rlink->rlink->data)
		{
			swap(a);
			write(1, "sa\n", 3);
		}
		return ;
	}
	if (n <= 1)
		return ;
	/*if (n == 13)
	{
		if (*debug > 4)
			exit(1);
		*debug += 1;
	}*/
	find_fivot(a, n, &d.f1, &d.f2);
	//printf("fivot : %d, %d\n", d.f1, d.f2);
	while (++(d.i) < n)
	{
		if (a->rlink->data >= d.f2)
		{
			rotate(a);
			write(1, "ra\n", 3);
			d.ra++;
		}
		else
		{
			push(b, a);
			write(1, "pb\n", 3);
			d.pb++;
			if (b->rlink->data >= d.f1)
			{
				rotate(b);
				write(1, "rb\n", 3);
				d.rb++;
			}
		}
	}
	d.i = -1;
	while (++d.i < d.ra)
	{
		r_rotate(a);
		write(1, "rra\n", 4);
	}
	d.i = -1;
	while (++d.i < d.rb)
	{
		r_rotate(b);
		write(1, "rrb\n", 4);
	}
	a_to_b(a, b, d.ra, debug);
	b_to_a(a, b, d.rb, debug);
	b_to_a(a, b, d.pb - d.rb, debug);
}

void	b_to_a(t_node *a, t_node *b, int n, int *debug)
{
	//printf("b_to_a(%d)\n", n);
	t_dat d;
	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk(b, n))
		return ;
	if (n == 2)
	{
		if (b->rlink->data < b->rlink->rlink->data)
		{
			swap(b);
			write(1, "sb\n", 3);
		}
		push(a, b);
		write(1, "pa\n", 3);
		push(a, b);
		write(1, "pa\n", 3);
		return ;
	}
	if (n == 1)
	{
		push(a, b);
		write(1, "pa\n", 3);
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
			rotate(b);
			write(1, "rb\n", 3);
			d.rb++;
		}
		else
		{
			push(a, b);
			write(1, "pa\n", 3);
			d.pa++;
			if (a->rlink->data < d.f2)
			{
				rotate(a);
				write(1, "ra\n", 3);
				d.ra++;
			}
		}
		
	}
	a_to_b(a, b, d.pa - d.ra, debug);
	d.i = -1;
	while (++d.i < d.ra)
	{
		r_rotate(a);
		write(1, "rra\n", 4);
	}
	d.i = -1;
	while (++d.i < d.rb)
	{
		r_rotate(b);
		write(1, "rrb\n", 4);
	}
	a_to_b(a, b, d.ra, debug);
	b_to_a(a, b, d.rb, debug);
}

void	quick_sort(t_node *a, t_node *b, int n)
{
	int debug;

	debug = 0;
	a_to_b(a, b, n, &debug);
	//find_fivot(a, n, &f1, &f2);
	print_list(a);
	print_list(b);
}