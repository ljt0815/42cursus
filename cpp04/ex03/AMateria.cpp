/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:46:39 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 10:28:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void)
{
	_type = "";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &am)
{
	_type = am.getType();
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &am)
{
	if (this != &am)
	{
		_type = am.getType();
	}
	std::cout << "AMateria assign operator called" << std::endl;
	return (*this);
}

std::string	const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "[Amateria] can't do anything to " << target.getName() << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}
