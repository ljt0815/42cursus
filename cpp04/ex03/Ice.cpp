/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:54:47 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 14:21:32 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria()
{
	_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	std::cout << "Ice string constructor called" << std::endl;
}

Ice::Ice(const Ice &i)
{
	_type = i.getType();
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &i)
{
	if (this != &i)
	{
		_type = i.getType();
	}
	std::cout << "Ice copy constructor called" << std::endl;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria *rtn = new Ice(*this);

	return (rtn);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}
