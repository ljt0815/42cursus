/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 15:00:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listnode.h"
#include "push_swap.h"

t_node	*in_first(t_node *head, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	if (head == 0)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return (head);
}

t_node	*in_last(t_node *head, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	if (head == 0)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return (head);
}

void	print_list(t_node *head)
{
	t_node *p;

	if (head == 0)
		return ;
	printf("%d->", head->data);
	p = head->link;
	while (p != head)
	{
		printf("%d->", p->data);
		p = p->link;
	}
}
