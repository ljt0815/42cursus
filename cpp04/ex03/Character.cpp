/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:35:32 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 06:50:38 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string	const &Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* am)
{
	int i;

	if (am == NULL)
		return ;
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
	_am[i] = NULL;
	std::cout << "[ unequip (" << i << ")]" << std::endl; 
}

void	Character::use(int idx, ICharacter &target)
{
	_am[idx]->use(target);
}
