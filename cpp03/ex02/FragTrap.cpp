/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:02:11 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 05:12:46 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "unnamed";
	_hp = _hpMax = 100;
	_ep = _epMax = 100;
	_ad = 30;
	std::cout << "FragTrap<" << _name << ">" << " created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	_name = name;
	_hp = _hpMax = 100;
	_ep = _epMax = 100;
	_ad = 30;
	std::cout << "FragTrap<" << _name << ">" << "created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap<" << _name << ">" << " destroyed" << std::endl;
}

void	FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap <" << _name << "> attacks <" << target << ">, causing <" << _ad << "> points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Let's HIGHFIVES!!?" << std::endl;
}
