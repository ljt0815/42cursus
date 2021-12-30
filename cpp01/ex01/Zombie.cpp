/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:54:40 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/30 22:43:46 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	this->announce();
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->name << "> " << "OOps...." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
