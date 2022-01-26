/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:37:15 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/26 21:36:55 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed b( 10 );
	Fixed c( 42.42f );
	Fixed a( 10 );

	std::cout << (c < b) << std::endl;
	std::cout << (c > b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << a + c << std::endl;
	std::cout << a - c << std::endl;
	std::cout << a * c << std::endl;
	std::cout << a / c << std::endl;
	return (0);
}
