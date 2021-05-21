/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:40:25 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/21 17:35:23 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft.h"
# include "listnode.h"
# include <unistd.h>
# include <stdlib.h>

void	swap(t_node *n);
void	push(t_node *n1, t_node *n2);
void	r_rotate(t_node *n);
void	rotate(t_node *n);

#endif
