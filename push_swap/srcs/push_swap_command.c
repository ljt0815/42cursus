/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:06:05 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/12 20:15:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(char c, t_node *a, t_node *b, t_node *msg)
{
	if (c == 'a')
	{
		rotate(a);
		node_lin(msg, RA);
	}
	else if (c == 'b')
	{
		rotate(b);
		node_lin(msg, RB);
	}
	else if (c == 'r')
	{
		rotate(a);
		rotate(b);
		node_lin(msg, RR);
	}
}

void	rr(char c, t_node *a, t_node *b, t_node *msg)
{
	if (c == 'a')
	{
		r_rotate(a);
		node_lin(msg, RRA);
	}
	else if (c == 'b')
	{
		r_rotate(b);
		node_lin(msg, RRB);
	}
	else if (c == 'r')
	{
		r_rotate(a);
		r_rotate(b);
		node_lin(msg, RRR);
	}
}

void	p(char c, t_node *a, t_node *b, t_node *msg)
{
	if (c == 'a')
	{
		push(a, b);
		node_lin(msg, PA);
	}
	else if (c == 'b')
	{
		push(b, a);
		node_lin(msg, PB);
	}
}

void	s(char c, t_node *a, t_node *b, t_node *msg)
{
	if (c == 'a')
	{
		swap(a);
		node_lin(msg, SA);
	}
	else if (c == 'b')
	{
		swap(b);
		node_lin(msg, SB);
	}
	else if (c == 's')
	{
		swap(a);
		swap(b);
		node_lin(msg, SS);
	}
}
