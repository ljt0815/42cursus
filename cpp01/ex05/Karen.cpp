/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:16:56 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/02 00:07:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "[debug]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[info]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[warning]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[error]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	void	(Karen::*f[27])(void) = {0};

	f[3] = &Karen::debug;
	f[4] = &Karen::error;
	f[8] = &Karen::info;
	f[22] = &Karen::warning;
	(this->*(f[level[0] - 'a']))();
}
