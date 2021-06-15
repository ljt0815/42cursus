/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:11:24 by jitlee            #+#    #+#             */
/*   Updated: 2021/06/15 10:29:29 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	overflow_chk(char *num, int len, int i)
{
	char	u_num[12];
	char	o_num[11];

	ft_strlcpy(u_num, "-2147483648", 12);
	ft_strlcpy(o_num, "2147483647", 11);
	if (num[0] == '-')
	{
		i = 0;
		if (len > 11)
			err_msg();
		if (len == 11)
			while (++i < 11)
				if (num[i] > u_num[i])
					err_msg();
	}
	else
	{
		i = -1;
		if (len > 10)
			err_msg();
		if (len == 10)
			while (++i < 10)
				if (num[i] > o_num[i])
					err_msg();
	}
}

void	all_digit_chk(int *ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (*ac == 2)
	{
		*ac = 0;
		while (av[*ac])
			(*ac)++;
		i = -1;
	}
	while (++i <= *ac - 1)
	{
		j = -1;
		while (++j < (int)ft_strlen(av[i]))
			if (ft_isdigit(av[i][j]))
				;
			else if (j == 0 && av[i][j] == '-' && av[i][1] != 0)
				;
			else
				err_msg();
		overflow_chk(av[i], j, 0);
	}
}

void	node_dup_chk(char **av, int len, int flag)
{
	char	**nums;
	int		i;
	int		j;
	int		av_len;
	int		nums_len;

	i = -1;
	flag = -(flag - 1);
	nums = malloc(sizeof(char *) * len);
	ft_bzero(nums, sizeof(nums));
	while (++i < len)
	{
		j = -1;
		av_len = ft_strlen(av[i + flag]);
		while (++j < i)
		{
			nums_len = ft_strlen(nums[j]);
			if (av_len > nums_len)
				nums_len = av_len;
			if (ft_strncmp(av[i + flag], nums[j], nums_len) == 0)
				err_msg();
		}
		nums[i] = av[i + flag];
	}
	free(nums);
}

int		main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;
	int		flag;

	flag = 0;
	a = malloc(sizeof(t_node));
	b = malloc(sizeof(t_node));
	init_node(a);
	init_node(b);
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		flag = 1;
	}
	i = 0 - flag;
	all_digit_chk(&ac, av);
	node_dup_chk(av, ac - 1 + flag, flag);
	while (++i <= ac - 1)
		node_lin(a, ft_atoi(av[i]));
	quick_sort(a, b, ac - 1 + flag);
	free_split(flag, av);
	return (0);
}
