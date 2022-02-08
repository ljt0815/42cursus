/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:24:30 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 09:10:24 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType(void) const
{
	return (_type);
}

Animal::Animal(void)
{
	_type = "";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
	_type = a.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &a)
{
	std::cout << "Animal assign operator called" << std::endl;
	if (this != &a)
	{
		_type = a.getType();
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal desturctor called" << std::endl;
}
