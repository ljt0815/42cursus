/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:54 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 03:32:02 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap <" << _name << "> : my name is " << _name << "!!!" << std::endl \
		<< "ClapTrap <" << ClapTrap::_name << "> : my name is " << ClapTrap::_name << "!!!!" << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

std::string	DiamondTrap::getName(void) const
{
	return (_name);
}

DiamondTrap::DiamondTrap(void) : FragTrap() , ScavTrap()
{
	_hp = _hpMax = F_HP;
	_ep = S_EP;
	_ad = F_AD;
	std::cout << "DiamondTrap<" << this->_name << ">" << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hp = _hpMax = F_HP;
	_ep = S_EP;
	_ad = F_AD;
	std::cout << "DiamondTrap<" << this->_name << ">" << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{
	_name = d.getName();
	_hp = d.getHp();
	_hpMax = d.getHpMax();
	_ep = d.getEp();
	_ad = d.getAd();
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &d)
{
	if (this != &d)
	{
		_name = d.getName();
		_hp = d.getHp();
		_hpMax = d.getHpMax();
		_ep = d.getEp();
		_ad = d.getAd();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap<" << _name << ">" << " destroyed" << std::endl;
}
