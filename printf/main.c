/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:22 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/10 13:13:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//char a = 'c';
	char *b = "qwer";
	//ft_printf("%c\n", a);
	//printf("%c\n", a);
	//printf("%d\n", ft_printf("%45c", a));
	//printf("%d\n", printf("%45c", a));
	//printf("%6s\n", b);
	//ft_printf("%6s\n", b);
	printf("%d\n", ft_printf("%3s", b));
	printf("%d\n", printf("%3s", b));
	return 0;
}
