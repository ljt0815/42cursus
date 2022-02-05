/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:02:11 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 01:27:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hp = _hpMax = F_HP;
	_ep = F_EP;
	_ad = F_AD;
	std::cout << "FragTrap<" << _name << ">" << " created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = _hpMax = F_HP;
	_ep = F_EP;
	_ad = F_AD;
	std::cout << "FragTrap<" << _name << ">" << "created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
	if (this != &f)
	{
		_name = f.getName();
		_hp = f.getHp();
		_hpMax = f.getHpMax();
		_ep = f.getEp();
		_ad = f.getAd();
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap<" << _name << ">" << " destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Let's HIGHFIVES!!?" << std::endl;
}

void	FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap <" << _name << "> attacks <" << target << ">, causing <" << _ad << "> points of damage!" << std::endl;
}
