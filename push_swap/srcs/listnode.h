/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:17 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 18:43:33 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_H
# define LISTNODE_H
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_node{
	int				data;
	struct s_node	*llink;
	struct s_node	*rlink;
}				t_node;

void			init_node(t_node *phead);
void			print_list(t_node *phead);
void			node_lin(t_node *before, int data);
void			node_rin(t_node *before, int data);
void			node_del(t_node *head, t_node *removed);
#endif
