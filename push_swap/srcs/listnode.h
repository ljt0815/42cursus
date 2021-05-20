/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:17 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 16:34:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_H
# define LIST_NODE_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node{
	int				data;
	struct s_node	*link;
}					t_node;

t_node	*in_first(t_node *head, int data);
t_node	*in_last(t_node *head, int data);
void	print_list(t_node *head);
#endif
