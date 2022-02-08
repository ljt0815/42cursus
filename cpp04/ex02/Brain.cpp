/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:50:21 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 05:45:35 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string	Brain::getString(int i) const
{
	return (_s[i]);
}

void	Brain::setString(std::string tmp, int i)
{
	_s[i] = tmp;
}

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	for (int i = 0; i < 100; i++)
		_s[i] = b._s[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	std::cout << "Brain assign operator called" << std::endl;
	if (this != &b)
	{
		for (int i = 0; i < 100; i++)
			_s[i] = b._s[i];
	}
	return (*this);
}

Brain::~Brain(void)
{	
	std::cout << "Brain desturctor called" << std::endl;
}

void	Brain::print(void)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << _s[i] << " ";
		if (i%10 == 0)
			std::cout << std::endl;
	}
}
