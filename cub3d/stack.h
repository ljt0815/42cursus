/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:38:01 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/16 08:05:39 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>
# define MAX_STACK_SIZE 100

typedef struct {
	int		x;
	int		y;
}			t_loc;

typedef struct {
	t_loc	data[MAX_STACK_SIZE];
	int		top;
}			t_stack;

void		init_stack(t_stack *s);
int			is_empty(t_stack *s);
int			is_full(t_stack *s);
void		push(t_stack *s, t_loc item);
t_loc		pop(t_stack *s);
#endif
