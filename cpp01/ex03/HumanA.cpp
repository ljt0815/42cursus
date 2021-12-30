/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:19:07 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 02:39:57 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), _w(w)
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->_w.getType() << std::endl;
}
