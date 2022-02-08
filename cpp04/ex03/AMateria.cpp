/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:46:39 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 10:27:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

std::string	const &Amateria::getType() const
{
	return (_type);
}

void	Amateria::use(ICharacter& target)
{

}
