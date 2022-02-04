/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:07:05 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 02:42:20 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	_name = "unnamed";
	_hp = _hpMax = 10;
	_ep = _epMax = 10;
	_ad = 0;
	std::cout << "<" << _name << ">" << " created" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	if (this != &c)
	{
		_name = c.getName();
		_hp = c.getHp();
		_ep = c.getEp();
		_ad = c.getAd();
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hp = _hpMax = 10;
	_ep = _epMax = 10;
	_ad = 0;
	std::cout << "<" << _name << ">" << "created" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap <" << _name << "> attacks <" << target << ">, causing <" << _ad << "> points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp < amount)
		_hp = 0;
	else
		_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp + amount > _hpMax)
		_hp = _hpMax;
	else
		_hp += amount;
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHp(void) const
{
	return (_hp);
}

int	ClapTrap::getEp(void) const
{
	return (_ep);
}

int	ClapTrap::getHpMax(void) const
{
	return (_hp);
}

int	ClapTrap::getEpMax(void) const
{
	return (_ep);
}

int	ClapTrap::getAd(void) const
{
	return (_ad);
}

void	ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void	ClapTrap::setHp(const int &hp)
{
	_hp = hp;
}

void	ClapTrap::setEp(const int &ep)
{
	_ep = ep;
}

void	ClapTrap::setAd(const int &ad)
{
	_ad = ad;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "<" << _name << ">" << " destroyed" << std::endl;
}
