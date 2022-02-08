/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:09:09 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 06:29:29 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void	MateriaSource::learnMateria(AMateria *am)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_am[i] != NULL)
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
		if (_am[i]->getType() == type)
			return (_am[i]->clone());
	}
	return (NULL);
}
