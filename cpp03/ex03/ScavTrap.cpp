/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:39:22 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 23:55:15 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hp = _hpMax = S_HP;
	_ep = S_EP;
	_ad = S_AD;
	std::cout << "ScavTrap<" << _name << ">" << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = _hpMax = S_HP;
	_ep = S_EP;
	_ad = S_AD;
	std::cout << "ScavTrap<" << _name << ">" << "created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &s)
{
	if (this != &s)
	{
		_name = s.getName();
		_hp = s.getHp();
		_hpMax = s.getHpMax();
		_ep = s.getEp();
		_ad = s.getAd();
	}
	return (*this);
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
