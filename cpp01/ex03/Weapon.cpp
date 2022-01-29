/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:04:56 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/29 11:42:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->str = str;
}

const std::string	&Weapon::getType(void) const
{
	return (this->str);
}

void		Weapon::setType(std::string str)
{
	this->str = str;
}
