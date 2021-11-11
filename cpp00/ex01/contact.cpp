/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:46:00 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/12 03:48:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int	Contact::chk_string(std::string str)
{
	int	i;

	if ((int)str.length() == 0)
		return (0);
	i = -1;
	while (++i < (int)str.length())
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			;
		else if (str[i] == ' ')
			;
		else
			break ;
	}
	if (i == (int)str.length())
		return (1);
	return (0);
}

int	Contact::chk_number(std::string str)
{
	int	i;

	if ((int)str.length() == 0)
		return (0);
	i = -1;
	while (++i < (int)str.length())
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] == '-')
			;
		else
			break ;
	}
	if (i == (int)str.length())
		return (1);
	return (0);
}

int	Contact::enter_string(std::string prt, std::string *pt)
{
	while (1)
	{
		std::cout << prt;
		if (!std::getline(std::cin, *pt) || std::cin.eof())
			return (-1);
		if (chk_string(*pt))
			break ;
		else
			std::cout << "ONLY SPACE OR ALPHABET" << std::endl;
	}
	return (0);
}

int	Contact::enter_number(std::string prt, std::string *pt)
{
	while (1)
	{
		std::cout << prt;
		if (!std::getline(std::cin, *pt) || std::cin.eof())
			return (-1);
		if (chk_number(*pt))
			break ;
		else
			std::cout << "ONLY NUMBER OR MINUS" << std::endl;
	}
	return (0);
}

void	Contact::fill_contact(int idx)
{
	this->idx = idx;
	if (enter_string("[1] first name : ", &this->first_name) == -1)
		return ;
	if (enter_string("[2] last name : ", &this->last_name) == -1)
		return ;
	if (enter_string("[3] nickname : ", &this->nickname) == -1)
		return ;
	if (enter_number("[4] phone number : ", &this->phone_number) == -1)
		return ;
	if (enter_string("[5] darkest secret : ", &this->darkest_secret) == -1)
		return ;
}

void	Contact::print_contact()
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

std::string	Contact::print_field(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	else
		return (std::string(10 - field.size(), ' ') + field);
}

void	Contact::print_short_info()
{
	std::cout << std::setw(10) << this->idx << \
		"|" << Contact::print_field(this->first_name) << \
		"|" << Contact::print_field(this->last_name) << \
		"|" << Contact::print_field(this->nickname) << \
		"|" << std::endl;
}
