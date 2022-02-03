/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:07:05 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/03 20:42:20 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default Constructor called" << std::endl;
	_hp = 10;
	_ep = 10;
	_ad = 0;
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
	_hp = 10;
	_ep = 10;
	_ad = 0;
}

void	ClapTrap::attack(std::string const & target)
{
	
}

std::string	ClapTrap::getName(void) const
{
	return (name);
}

int	ClapTrap::getHp(void) const
{
	return (hp);
}

int	ClapTrap::getEp(void) const
{
	return (ep);
}

int	ClapTrap::getAd(void) const
{
	return (ad);
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
	std::cout << "Destructor called" << std::endl;
}
