/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:16:56 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/03 06:04:48 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::unknown(void)
{
	std::cout << "[UNKNOWN]" << std::endl;
	std::cout << "I don't know what i'm say" << std::endl;
}

void	Karen::complain(std::string level)
{
	void	(Karen::*f[5])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::unknown};
	std::string	words[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i = -1;

	while (level != words[++i] && i < 4)
		;
	(this->*(f[i]))();
}
