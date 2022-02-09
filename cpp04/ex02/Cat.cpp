/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:13:38 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 12:53:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << "mewo mewo ^   ^" << std::endl;
	std::cout << "	 (◕‿‿◕｡)    l" << std::endl;
	std::cout << "	    UU    UU" << std::endl;
}

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	_b = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	_b = new Brain();
	_type = c.getType();
	for (int i = 0; i < 100; i++)
		_b->setString(c.getBrainStr(i), i);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat assign operator called" << std::endl;
	if (this != &c)
	{
		_type = c.getType();
		for (int i = 0; i < 100; i++)
			_b->setString(c.getBrainStr(i), i);
	}
	return (*this);
}

std::string	Cat::getBrainStr(int i) const
{
	return (_b->getString(i));
}

void	Cat::setBrainStr(std::string tmp, int i)
{
	_b->setString(tmp, i);
}

void	Cat::brainScan(void)
{
	_b->print();
}

Cat::~Cat(void)
{
	std::cout << "Cat desturctor called" << std::endl;
	delete _b;
}
