/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:40:05 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 01:56:12 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{

	std::cout << "<list test>" << std::endl;
	try
	{
		std::list<int> a;
		for (int i=0; i<5; i++)
			a.push_back(i);
		std::list<int>::iterator a_it = easyfind(a, 3);
		std::cout << *a_it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "<vector test>" << std::endl;
	try
	{
		std::vector<int> b;
		for (int i=0; i<5; i++)
			b.push_back(i);
		std::vector<int>::iterator b_it = easyfind(b, 6);
		std::cout << *b_it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "<deque test>" << std::endl;
	try
	{
		std::deque<int> c;
		for (int i=0; i<5; i++)
			c.push_back(i);
		std::deque<int>::iterator c_it = easyfind(c, 0);
		std::cout << *c_it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

}
