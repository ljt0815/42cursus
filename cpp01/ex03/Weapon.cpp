/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:04:56 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 00:25:16 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->str = str;
}

std::string	Weapon::getType(void)
{
	return (this->str);
}

void		Weapon::setType(std::string str)
{
	this->str = str;
}
