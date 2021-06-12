/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:06:05 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/12 12:39:12 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(char c, t_node *a, t_node *b)
{
	if (c == 'a')
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}

void	rr(char c, t_node *a, t_node *b)
{
	if (c == 'a')
	{
		r_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		r_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		r_rotate(a);
		r_rotate(b);
		write(1, "rrr\n", 4);
	}
}

void	p(char c, t_node *a, t_node *b)
{
	if (c == 'a')
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
}

void	s(char c, t_node *a, t_node *b)
{
	if (c == 'a')
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}
