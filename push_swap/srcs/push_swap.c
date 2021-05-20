/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:38:39 by jitlee            #+#    #+#             */
/*   Updated: 2021/05/20 16:35:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "listnode.h"

void	err_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	all_digit_chk(int ac, char **av)
{
	int i;
	int j;
	int len;

	i = 0;
	while (++i <= ac - 1)
	{
		j = -1;
		len = ft_strlen(av[i]);
		while (++j < len)
			if (!ft_isdigit(av[i][j]))
				err_msg("argument is ONLY number");
	}
}

int		main(int ac, char **av)
{
	t_node	*a;

	a = 0;
	if (ac == 1)
		err_msg("Not enough arguments.");
	all_digit_chk(ac, av);
	a = in_first(a, ft_atoi(av[1]));
	print_list(a);
	return (0);
}
