/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:15:49 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 15:16:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Casting.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Useage : ./convert NUMBER" << std::endl;
		return (1);
	}
	Casting c(av[1]);
	std::cout << c << std::endl;
	return (0);
}
