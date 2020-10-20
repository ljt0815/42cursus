/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:47:35 by dongklee          #+#    #+#             */
/*   Updated: 2020/10/17 15:31:25 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int idx;
	int flag;
	int result;

	idx = 0;
	flag = 1;
	result = 0;
	while (str[idx] == ' ' || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	if (str[idx] == '-')
		flag = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result = (result * 10) + ((int)str[idx] - '0');
		idx++;
	}
	return (flag * result);
}
