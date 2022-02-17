/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:41:20 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/17 23:25:25 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> list;
	for (int i = 0; i < 5; i++)
		list.push_back(i);
	std::list<int>::iterator l_iter = easyfind(list, 4);
	std::cout << *l_iter << std::endl;
	try {
		std::list<int>::iterator l_iter2 = easyfind(list, 5);
		std::cout << *l_iter2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(i);
	std::vector<int>::iterator v_iter = easyfind(v, 4);
	std::cout << *v_iter << std::endl;
	try {
		std::vector<int>::iterator v_iter2 = easyfind(v, 5);
		std::cout << *v_iter2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> d;
	for (int i = 0; i < 5; i++)
		d.push_back(i);
	std::deque<int>::iterator d_iter = easyfind(d, 4);
	std::cout << *d_iter << std::endl;
	try {
		std::deque<int>::iterator d_iter2 = easyfind(d, 5);
		std::cout << *d_iter2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
