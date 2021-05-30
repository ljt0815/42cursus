/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:37:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/25 19:58:53 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *n)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = n->rlink;
	tmp2 = n->rlink->rlink;
	n->rlink = tmp2;
	tmp->rlink = tmp2->rlink;
	tmp2->rlink = tmp;
	tmp->llink = tmp2;
	tmp2->llink = n;
}

void	push(t_node *n1, t_node *n2)
{
	t_node	*tmp;

	if (n2->rlink == n2)
		return ;
	tmp = n2->rlink;
	n2->rlink = tmp->rlink;
	tmp->rlink->llink = n2;
	n1->rlink->llink = tmp;
	tmp->rlink = n1->rlink;
	n1->rlink = tmp;
	tmp->llink = n1;
}

void	rotate(t_node *n)
{
	t_node	*tmp;

	if (n->rlink == n)
		return ;
	tmp = n->rlink;
	n->rlink->rlink->llink = n;
	n->rlink = n->rlink->rlink;
	n->llink->rlink = tmp;
	tmp->llink = n->llink;
	tmp->rlink = n;
	n->llink = tmp;
}

void	r_rotate(t_node *n)
{
	t_node	*tmp;

	if (n->llink == n)
		return ;
	tmp = n->llink;
	n->llink->llink->rlink = n;
	n->llink = n->llink->llink;
	n->rlink->llink = tmp;
	tmp->rlink = n->rlink;
	tmp->llink = n;
	n->rlink = tmp;
}
