/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:58:41 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/12 00:21:47 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	p;
	while (1)
	{
		if (std::cin.eof())
			break ;
		std::cout << "PhoneBook $ ";
		std::cin >> cmd;
		if (cmd == "ADD")
			p.p_add();
		else if (cmd == "SEARCH")
			p.p_search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "command not found" << std::endl;
	}
	return (0);
}
