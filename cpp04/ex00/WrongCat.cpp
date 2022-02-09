/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:35:16 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 12:55:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound(void) const
{
	std::cout << "owem owem ^   ^" << std::endl;
	std::cout << "	 (◕‿‿◕｡)    s" << std::endl;
	std::cout << "	    nn    nn" << std::endl;
}

WrongCat::WrongCat(void) : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc)
{
	_type = wc.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &wc)
{
	std::cout << "WrongCat assign operator called" << std::endl;
	if (this != &wc)
	{
		_type = wc.getType();
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat desturctor called" << std::endl;
}
