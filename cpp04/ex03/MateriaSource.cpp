/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:09:09 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 09:04:29 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_am[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *am)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_am[i] == NULL)
		{
			_am[i] = am;
			break ;
		}
	}
	if (i == 4)
		std::cout << "[FAIL] Materia is FULL" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_am[i] != NULL)
		{
			if (_am[i]->getType() == type)
				return (_am[i]->clone());
		}
	}
	return (NULL);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (_am[i] != NULL)
			delete _am[i];
	std::cout << "MateriaSource destructor  called" << std::endl;
}
