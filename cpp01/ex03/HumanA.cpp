/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:19:07 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 00:30:39 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w)
{
	this->w = &w;
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}
