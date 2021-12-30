/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:31:10 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 02:43:20 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->w = NULL;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}

void	HumanB::attack(void)
{
	if (this->w == NULL)
		std::cout << this->name << " attacks with his right hand" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}
