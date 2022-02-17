/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:15:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 01:30:24 by jitlee           ###   ########.fr       */
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
	std::cout << "deleted sp" << std::endl;
	std::cout << "sp2 :";
	sp2.print();

	Span sp3(30);
	sp3.addNumber("3 1 2 4 5 6 7 8 9 10 23 145 23 0 2 3");
	std::cout << "sp3 :";
	sp3.print();
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;


}
