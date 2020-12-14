/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:22 by jitlee            #+#    #+#             */
/*   Updated: 2020/12/14 15:21:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//char a = 'c';
	//char *b = "qwer";
	int	c = 124;
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
	//printf("%30d\n", c);
	//ft_printf("%30d", c);
	printf("%d\n", printf("%020d", c));
	printf("%d", ft_printf("%020d", c));
	return 0;
}
