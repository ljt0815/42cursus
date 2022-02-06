/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:57:18 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/07 06:48:48 by jitlee           ###   ########.fr       */
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
	_type = "";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	_type = d.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << "Dog assign operator called" << std::endl;
	if (this != &d)
	{
		_type = d.getType();
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog desturctor called" << std::endl;
}
