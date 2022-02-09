/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:13:38 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 12:52:46 by jitlee           ###   ########.fr       */
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
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	_type = c.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat assign operator called" << std::endl;
	if (this != &c)
	{
		_type = c.getType();
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat desturctor called" << std::endl;
}
