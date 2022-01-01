/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:04:31 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/02 01:34:47 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int ac, char *av[])
{
	Karen k;

	if (ac != 2)
	{
		std::cout << "arguments must 2" << std::endl;
		return (1);
	}
	k.complain(av[1]);
	return (0);
}
