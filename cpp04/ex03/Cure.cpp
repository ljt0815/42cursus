/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:19:23 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 10:29:29 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria()
{
	_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure string constructor called" << std::endl;
}

Cure::Cure(const Cure &c)
{
	_type = c.getType();
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &c)
{
	if (this != &c)
	{
		_type = c.getType();
	}
	std::cout << "Cure assign operator called" << std::endl;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	AMateria *rtn = new Cure(*this);

	return (rtn);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}
