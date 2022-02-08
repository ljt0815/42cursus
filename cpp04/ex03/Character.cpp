/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:35:32 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 08:38:57 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name)
{
	_name = name;
	std::cout << "Character string constructor called" << std::endl;
}

std::string	const &Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* am)
{
	int i;

	if (am == NULL)
	{
		std::cout << "AMateria is NULL" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++)
	{
		if (_am[i] == NULL)
		{
			_am[i] = am;
			break ;
		}
	}
	if (i == 4)
		std::cout << "Inventory is FULL" << std::endl;
}

void	Character::unequip(int idx)
{
	_am[idx] = NULL;
	std::cout << "[ unequip (" << idx << ")]" << std::endl; 
}

void	Character::use(int idx, ICharacter &target)
{
	_am[idx]->use(target);
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
}
