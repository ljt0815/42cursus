/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:51:12 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 17:24:53 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> a(10);

	try {
		for (unsigned int i = 0; i < a.getLen(); i++)
			a[i] = i;
		for (unsigned int i = 0; i < a.getLen(); i++)
			std::cout << a[i] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	const Array<int> b = a;

	try {
		for (unsigned int i = 0; i < b.getLen(); i++)
			b[i] = b.getLen() - i;
		for (unsigned int i = 0; i < b.getLen(); i++)
			std::cout << b[i] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		a[10] = 1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b[10] = 1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
