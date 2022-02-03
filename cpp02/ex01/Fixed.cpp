/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:53:20 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/03 14:42:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &f)
		this->fixed_point = f.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / (1 << fixed_bit));
}

int	Fixed::toInt(void) const
{
	return (fixed_point >> fixed_bit);
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = static_cast<int>(roundf(raw * (1<<fixed_bit)));
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = raw << fixed_bit;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	return o << f.toFloat();
}
