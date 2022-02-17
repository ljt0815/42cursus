/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:41:20 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/17 22:37:26 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> list;
	for (int i = 0; i < 5; i++)
		list.push_back(i);
	std::list<int>::iterator iter = easyfind(list, 4);
	std::cout << *iter << std::endl;
	try {
		std::list<int>::iterator iter2 = easyfind(list, 5);
		std::cout << *iter2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
