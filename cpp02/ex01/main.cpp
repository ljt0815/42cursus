/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:53:38 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/20 19:18:58 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b( 10 );
	//Fixed const	c( 42.42f );
	//Fixed const	d( b );
	
	//a = Fixed( 1234.4321f );

	//std::cout << "a is " << a << std::endl;
	//std::cout << "b is " << b << std::endl;

	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	return (0);
}
