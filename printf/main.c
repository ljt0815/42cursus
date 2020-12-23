/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:22 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/24 00:58:24 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//char a = 'c';
	//char *b = "qwer";
	int	c = -123;
	//ft_printf("%c\n", a);
	//printf("%-10c\n", a);
	//printf("%d\n", ft_printf("%3c", a));
	//printf("%d\n", printf("%3c", a));
	//printf("%-6.2s\n", b);
	//ft_printf("%-6.2s\n", b);
	//printf("%d\n", ft_printf("%-6.2s", b));
	//printf("%d\n", printf("%-6.2s", b));
	//printf("%d\n", ft_printf("a%c34%9.1s",'d',"qwer"));
	//printf("%d\n", printf("a%c34%9.1s",'d',"qwer"));
	//printf("%d\n", printf("%-20p\n", b));
	//printf("%d", ft_printf("%-20p\n", b));
	//printf(" %d\n", printf("%30p", b));
	//printf(" %d", ft_printf("%30p", b));
	ft_printf("%7.5d\n", c);
	printf("%7.5d", c);
	//printf("%d\n", printf("%20.5d", c));
	//printf("%d", ft_printf("%20.5d", c));
	return 0;
}
