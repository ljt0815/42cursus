/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:04:56 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 02:38:38 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string str)
{
	this->str = str;
}

const std::string	&Weapon::getType(void)
{
	return (this->str);
}

void		Weapon::setType(std::string str)
{
	this->str = str;
}
