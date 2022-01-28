/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:37:15 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/28 17:50:14 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed b( 10 );
	Fixed c( 42.42f );
	Fixed a( 10 );
	Fixed const d( 3 );
	Fixed const e( 1 );

	std::cout << (c < b) << std::endl;
	std::cout << (c > b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << a + c << std::endl;
	std::cout << a - c << std::endl;
	std::cout << a * c << std::endl;
	std::cout << a / c << std::endl;
	std::cout << a++ << std::endl;
	std::cout << ++a << std::endl;
	std::cout << b-- << std::endl;
	std::cout << --b << std::endl;
	Fixed const &w = Fixed::max(e, d);
	std::cout << w << std::endl;
	return (0);
}
