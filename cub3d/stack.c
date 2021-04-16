/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:37:43 by jitlee            #+#    #+#             */
/*   Updated: 2021/04/16 08:01:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "cub3d.h"

void	init_stack(t_stack *s)
{
	s->top = -1;
}

int		is_empty(t_stack *s)
{
	return (s->top == -1);
}

int		is_full(t_stack *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void	push(t_stack *s, t_loc item)
{
	if (is_full(s))
		err_msg("STACK FULL ERROR");
	s->data[++(s->top)] = item;
}

t_loc	pop(t_stack *s)
{
	if (is_empty(s))
		err_msg("STACK EMPTY ERROR");
	return s->data[(s->top)--];
}
