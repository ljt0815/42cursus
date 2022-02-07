/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 03:13:37 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 05:08:18 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int main()
{

	std::cout << "subject test" << std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;



	std::cout << "basic test" << std::endl << std::endl;

	Span a(3);

	try {
		a.addNumber(1);
		// a.addNumber(5);
		// a.addNumber(100);
		// a.addNumber(1);
		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "big test" << std::endl << std::endl;


	Span b(10000);
	try {
		for (int i=0; i<10000; i++)
			b.addNumber(i);
		std::cout << b.shortestSpan() << std::endl;
		std::cout << b.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "random test" << std::endl << std::endl;

	Span c(200);
	srand(time(NULL));
	try {
		for (int i=0; i<200; i++)
			c.addNumber(rand());
		std::cout << c.shortestSpan() << std::endl;
		std::cout << c.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
