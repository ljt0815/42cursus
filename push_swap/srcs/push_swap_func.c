/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:37:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 21:01:23 by jitlee           ###   ########.fr       */
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

void	reverse(t_node *n)
{
	
}
