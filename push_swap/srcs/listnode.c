/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/31 21:07:08 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
	phead->data = -2147483648;
}

void	print_list(t_node *phead)
{
	t_node	*p;

	p = phead->rlink;
	while (p != phead)
	{
		printf("<-| |%d| |-> ", p->data);
		p = p->rlink;
	}
	printf("\n");
}

void	node_lin(t_node *before, int data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->llink = before->llink;
	node->rlink = before;
	before->llink->rlink = node;
	before->llink = node;
}

void	node_rin(t_node *before, int data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->llink = before;
	node->rlink = before->rlink;
	before->rlink->llink = node;
	before->rlink = node;
}

void	node_del(t_node *head, t_node *removed)
{
	if (removed == head)
		return ;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
