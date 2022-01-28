/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:37:19 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/28 17:53:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &f)
		this->fixed_point = f.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &f) const
{
	return fixed_point < f.getRawBits();
}

bool Fixed::operator>(const Fixed &f) const
{
	return fixed_point > f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const
{
	return fixed_point <= f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const
{
	return fixed_point >= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) const
{
	return fixed_point == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) const
{
	return fixed_point != f.getRawBits();
}

Fixed Fixed::operator+(const Fixed &f)
{
	Fixed tmp(this->toFloat() + f.toFloat());

	return tmp;
}

Fixed Fixed::operator-(const Fixed &f)
{
	Fixed tmp(this->toFloat() - f.toFloat());

	return tmp;
}

Fixed Fixed::operator*(const Fixed &f)
{
	Fixed tmp(this->toFloat() * f.toFloat());

	return tmp;
}

Fixed Fixed::operator/(const Fixed &f)
{
	Fixed tmp(this->toFloat() / f.toFloat());

	return tmp;
}

Fixed Fixed::operator++()
{
	fixed_point += 1;

	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	fixed_point += 1;

	return tmp;
}

Fixed Fixed::operator--()
{
	fixed_point -= 1;

	return *this;
}

const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	fixed_point -= 1;

	return tmp;
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
	//std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(raw * (1<<fixed_bit));
}

Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	if (raw >= 8388608)
	{
		std::cout << "INTEGER OVERFLOW" << std::endl;
	}
	fixed_point = raw << fixed_bit;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	//std::cout << "static min" << std::endl;
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	return f2;
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	//std::cout << "const min" << std::endl;
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	return f2;
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	//std::cout << "static max" << std::endl;
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	return f2;
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	//std::cout << "const max" << std::endl;
	if ((Fixed)f1.getRawBits() > (Fixed)f2.getRawBits())
		return f1;
	return f2;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	return o << f.toFloat();
}
