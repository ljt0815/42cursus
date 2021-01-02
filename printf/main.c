/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:22 by jitlee            #+#    #+#             */
/*   Updated: 2021/01/02 20:19:26 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	//char	*n = "abcdefghijklmnop";
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	//printf("%*i\n", 14, 94827);
	ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d);
	printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d);
	return 0;
}
