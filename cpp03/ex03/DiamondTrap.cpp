/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:54 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 21:04:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap() , ScavTrap()
{
	_name = "unnamed";
	_hp = _hpMax = 100;
	_ep = _epMax = 50;
	_ad = 30;
	std::cout << "DiamondTrap<" << this->_name << ">" << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap<" << _name << ">" << " destroyed" << std::endl;
}
