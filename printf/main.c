/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:22 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 18:19:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//char a = 'c';
	//char *b = "qwer";
	//ft_printf("%c\n", a);
	//printf("%c\n", a);
	//printf("%d\n", ft_printf("%45c", a));
	//printf("%d\n", printf("%45c", a));
	//printf("%6.2s\n", b);
	//ft_printf("%6.2s\n", b);
	//printf("%d\n", ft_printf("%3.2s", b));
	//printf("%d\n", printf("%3.2s", b));
	//printf("%d\n", ft_printf("%3.2s", b));
	//printf("%d\n", printf("%3.2s", b));
	printf("%-2",3);
	ft_printf("%-2",3);
	return 0;
}
