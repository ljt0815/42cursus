#include "push_swap.h"

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
	t_node	*b;
	int		i;

	a = malloc(sizeof(t_node));
	b = malloc(sizeof(t_node));
	init_node(a);
	init_node(b);
	i = 0;
	if (ac == 1)
		err_msg("Not enough arguments.");
	all_digit_chk(ac, av);
	while (++i <= ac - 1)
		node_lin(a, ft_atoi(av[i]));
	quick_sort(a, b, ac - 1);
	return (0);
}
