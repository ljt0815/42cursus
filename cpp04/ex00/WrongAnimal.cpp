/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:19:29 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/07 22:35:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound(void) const
{
	std::cout << "...(Wrong)" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

WrongAnimal::WrongAnimal(void)
{
	_type = "";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	_type = wa.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal assign operator called" << std::endl;
	if (this != &wa)
	{
		_type = wa.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal desturctor called" << std::endl;
}
