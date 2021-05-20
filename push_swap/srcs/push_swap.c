/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:38:39 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 13:46:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		err_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	return (0);
}

int		main(int ac, char **av)
{
	int *a;
	int	*b;

	if (ac == 1)
		return (err_msg("Not enough arguments."));
	a = malloc(sizeof(int) * (ac - 1));
	b = malloc(sizeof(int) * (ac - 1));
	write(1, av[1], ft_strlen(av[1]));
	return (0);
}
