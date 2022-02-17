/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:15:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 02:19:41 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	Span *sp = new Span(5);
	sp->addNumber(5);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(11);

	Span sp2 = Span(10);
	sp2.addNumber(8);
	sp2.addNumber(4);
	sp2.addNumber(2);
	sp2.addNumber(3);
	sp2.addNumber(1);
	sp2.addNumber(13);
	sp2.addNumber(19);
	sp2.addNumber(21);
	sp2.addNumber(35);
	sp2.addNumber(7);

	sp2 = *sp;
	std::cout << sp->shortestSpan() << std::endl;
	std::cout << sp->longestSpan() << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "sp :";
	sp->print();
	delete sp;
	std::cout << "[deleted sp]" << std::endl;
	std::cout << "sp2 :";
	sp2.print();

	Span sp3(30);
	sp3.addNumber("123 145 248 450 236 197 408 1239 41210 1123 3145 523 70 815 93");
	std::cout << "sp3 :";
	sp3.print();
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	/*Span sp4(10000);
	sp4.addRandomNumber(10000);
	std::cout << "sp4 :";
	sp4.print();
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;*/
}
