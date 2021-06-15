/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 09:43:07 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
	phead->data = 0;
}

void	print_list(t_node *phead)
{
	char	*num;
	t_node	*p;

	p = phead->rlink;
	while (p != phead)
	{
		num = ft_itoa(p->data);
		write(1, "<-| |", 5);
		write(1, num, ft_strlen(num));
		write(1, "| |->", 5);
		free(num);
		p = p->rlink;
	}
	write(1, "\n", 1);
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
