/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:57:18 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 12:53:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound(void) const
{
	std::cout << "bowwow bowwow  (∪￣ᴥ￣∪)  l" << std::endl \
		<< "		UU      UU" << std::endl;
}

Dog::Dog(void) : Animal()
{
	_type = "Dog";
	_b = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	_b = new Brain();
	_type = d.getType();
	for (int i = 0; i < 100; i++)
		_b->setString(d.getBrainStr(i), i);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << "Dog assign operator called" << std::endl;
	if (this != &d)
	{
		_type = d.getType();
		for (int i = 0; i < 100; i++)
			_b->setString(d.getBrainStr(i), i);
	}
	return (*this);
}

std::string	Dog::getBrainStr(int i) const
{
	return (_b->getString(i));
}

void	Dog::setBrainStr(std::string tmp, int i)
{
	_b->setString(tmp, i);
}

void	Dog::brainScan(void)
{
	_b->print();
}

Dog::~Dog(void)
{
	std::cout << "Dog desturctor called" << std::endl;
	delete _b;
}
