/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:53:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 04:37:12 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	
	ClapTrap bot("bot");
	ClapTrap enemy("enemy");

	std::cout << "enemy HP : " << enemy.getHp() << std::endl;
	bot.attack("enemy");
	enemy.takeDamage(bot.getAd());
	std::cout << "enemy HP : " << enemy.getHp() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "bot Attack Damage setting 10!!!" << std::endl;
	bot.setAd(10);
	bot.attack("enemy");
	enemy.takeDamage(bot.getAd());
	std::cout << "enemy HP : " << enemy.getHp() << std::endl;
	std::cout << "enemy self repaired 5" << std::endl;
	enemy.beRepaired(5);
	std::cout << "enemy HP : " << enemy.getHp() << std::endl;
	//enemy.guardGate();

	std::cout << std::endl << "-------------------------------------------------" << std::endl << std::endl;

	ScavTrap bot2("bot");
	ScavTrap enemy2("enemy");

	std::cout << "enemy HP : " << enemy2.getHp() << std::endl;
	bot2.attack("enemy");
	enemy2.takeDamage(bot2.getAd());
	std::cout << "enemy HP : " << enemy2.getHp() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "bot Attack Damage setting 10!!!" << std::endl;
	bot2.setAd(10);
	bot2.attack("enemy");
	enemy2.takeDamage(bot2.getAd());
	std::cout << "enemy HP : " << enemy2.getHp() << std::endl;
	std::cout << "enemy self repaired 5" << std::endl;
	enemy2.beRepaired(5);
	std::cout << "enemy HP : " << enemy2.getHp() << std::endl;
	enemy2.guardGate();
	
	return (0);
}
