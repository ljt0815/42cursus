/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 05:39:09 by marvin            #+#    #+#             */
/*   Updated: 2021/06/12 21:08:14 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

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

void	mini_find_fivot(t_node *node, int n, int *f)
{
	int		*arr;
	int		i;

	i = -1;
	arr = malloc(sizeof(int) * (n + 1));
	while (++i < n)
	{
		node = node->rlink;
		arr[i] = node->data;
	}
	bubble_sort(arr, n);
	*f = arr[(n / 2)];
	free(arr);
}

void	find_fivot(t_node *node, int n, int *f1, int *f2)
{
	int		*arr;
	int		i;

	i = -1;
	arr = malloc(sizeof(int) * (n + 1));
	while (++i < n)
	{
		node = node->rlink;
		arr[i] = node->data;
	}
	bubble_sort(arr, n);
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

void	rrx(t_node *a, t_node *b, t_dat *d, t_node *msg)
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
		rr('r', a, b, msg);
	d->i = -1;
	if (flag == 0)
		while (++d->i < d->rb - d->ra)
			rr('b', a, b, msg);
	else
		while (++d->i < d->ra - d->rb)
			rr('a', a, b, msg);
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
			break ;
	}
	if (i == n)
		return (1);
	return (0);
}

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
			break ;
	}
	if (i == n)
		return (1);
	return (0);
}

void	mini_a_to_b(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk_a(a, n))
		return ;
	if (n <= 2)
	{
		if (n == 2)
			s('a', a, b, msg);
		return ;
	}
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
	if (sorting_chk_b(b, n))
	{
		while (++d.i < n)
			p('a', a, b, msg);
		return ;
	}
	if (n <= 2)
	{
		if (n == 2)
			s('b', a, b, msg);
		while (++d.i < n)
			p('a', a, b, msg);
		return ;
	}
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

void	a_to_b(t_node *a, t_node *b, int n, t_node *msg)
{
	t_dat d;

	ft_bzero(&d, sizeof(t_dat));
	d.i = -1;
	if (sorting_chk_a(a, n))
		return ;
	if (n <= 2)
	{
		if (n == 2)
			s('a', a, b, msg);
		return ;
	}
	find_fivot(a, n, &d.f1, &d.f2);
	while (++(d.i) < n)
	{
		if (a->rlink->data >= d.f2)
		{
			r('a', a, b, msg);
			d.ra++;
		}
		else
		{
			p('b', a, b, msg);
			d.pb++;
			if (b->rlink->data >= d.f1)
			{
				r('b', a, b, msg);
				d.rb++;
			}
		}
	}
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
	if (sorting_chk_b(b, n))
	{
		while (++d.i < n)
			p('a', a, b, msg);
		return ;
	}
	if (n <= 2)
	{
		if (n == 2)
			s('b', a, b, msg);
		while (++d.i < n)
			p('a', a, b, msg);
		return ;
	}
	find_fivot(b, n, &d.f1, &d.f2);
	while (++(d.i) < n)
	{
		if (b->rlink->data < d.f1)
		{
			r('b', a, b, msg);
			d.rb++;
		}
		else
		{
			p('a', a, b, msg);
			d.pa++;
			if (a->rlink->data < d.f2)
			{
				r('a', a, b, msg);
				d.ra++;
			}
		}
	}
	a_to_b(a, b, d.pa - d.ra, msg);
	rrx(a, b, &d, msg);
	a_to_b(a, b, d.ra, msg);
	b_to_a(a, b, d.rb, msg);
}

void	print_msg(t_node *msg)
{
	t_node *p;

	p = msg->rlink;
	while (p != msg)
	{
		if (p->data == RA)
			write(1, "ra\n", 3);
		else if (p->data == RB)
			write(1, "rb\n", 3);
		else if (p->data == RR)
			write(1, "rr\n", 3);
		else if (p->data == RRA)
			write(1, "rra\n", 4);
		else if (p->data == RRB)
			write(1, "rrb\n", 4);
		else if (p->data == RRR)
			write(1, "rrr\n", 4);
		else if (p->data == PA)
			write(1, "pa\n", 3);
		else if (p->data == PB)
			write(1, "pb\n", 3);
		else if (p->data == SA)
			write(1, "sa\n", 3);
		else if (p->data == SB)
			write(1, "sb\n", 3);
		else if (p->data == SS)
			write(1, "ss\n", 3);
		else
			write(2, "ERROR\n", 6);
		p = p->rlink;
	}
}

void	optimize_msg(t_node *msg)
{
	t_node *p;

	p = msg->rlink;
	while (p != msg)
	{
		if (p->data == RA && p->llink->data == RB)
		{
			node_del(msg, p->llink);
			p->data = RR;
		}
		else if (p->data == RB && p->llink->data == RA)
		{
			node_del(msg, p->llink);
			p->data = RR;
		}
		else if (p->data == RRA && p->llink->data == RRB)
		{
			node_del(msg, p->llink);
			p->data = RRR;
		}
		else if (p->data == RRB && p->llink->data == RRA)
		{
			node_del(msg, p->llink);
			p->data = RRR;
		}
		else if (p->data == SB && p->llink->data == SA)
		{
			node_del(msg, p->llink);
			p->data = SS;
		}
		else if (p->data == SA && p->llink->data == SB)
		{
			node_del(msg, p->llink);
			p->data = SS;
		}
		p = p->rlink;
	}
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
