/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:30:06 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 04:31:58 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
