/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:53:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 03:43:07 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("kkk");

	std::cout << a.getHp() << std::endl;	
	std::cout << a.getEp() << std::endl;	
	std::cout << a.getAd() << std::endl;	
	a.guardGate();
	a.highFivesGuys();
	a.attack("bot");
	std::cout << "--------------------whoAmI()---------------------" << std::endl;
	a.whoAmI();
	std::cout << "-------------------------------------------------" << std::endl;

	return (0);
}
