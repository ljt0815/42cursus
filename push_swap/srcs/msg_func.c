/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:04:17 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 10:24:32 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_msg2(t_node *p)
{
	if (p->data == PA)
	{
		write(1, "pa\n", 3);
		return (1);
	}
	else if (p->data == PB)
	{
		write(1, "pb\n", 3);
		return (1);
	}
	else if (p->data == SA)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else if (p->data == SB)
	{
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
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
		else if (p->data == SS)
			write(1, "ss\n", 3);
		else if (print_msg2(p))
			;
		else
			err_msg();
		p = p->rlink;
	}
}

void	optimize_msg2(t_node *p, t_node *msg)
{
	if (p->data == RRB && p->llink->data == RRA)
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
		else
			optimize_msg2(p, msg);
		p = p->rlink;
	}
}
