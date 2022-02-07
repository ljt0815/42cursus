/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:50:21 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 00:53:11 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	memcpy(_s, b._s, sizeof(_s));
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	std::cout << "Brain assign operator called" << std::endl;
	if (this != &b)
	{
		memcpy(_s, b._s, sizeof(_s));
	}
	return (*this);
}

Brain::~Brain(void)
{	
	std::cout << "Brain desturctor called" << std::endl;
}
