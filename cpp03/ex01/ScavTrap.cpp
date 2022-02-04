/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:39:22 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 04:29:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	_name = "unnamed";
	_hp = _hpMax = 100;
	_ep = _epMax = 50;
	_ad = 20;
	std::cout << "ScavTrap<" << _name << ">" << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hp = _hpMax = 100;
	_ep = _epMax = 50;
	_ad = 20;
	std::cout << "ScavTrap<" << _name << ">" << "created" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap<" << _name << ">" << " destroyed" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Gate keeper mode O.N.!!!!!!" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap <" << _name << "> attacks <" << target << ">, causing <" << _ad << "> points of damage!" << std::endl;
}
