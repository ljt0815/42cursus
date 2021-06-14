/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:25:50 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 04:28:26 by jitlee           ###   ########.fr       */
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
