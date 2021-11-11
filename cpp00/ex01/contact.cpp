/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:46:00 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/11 22:24:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::fill_contact(int idx)
{
	this->idx = idx;
	std::cout << "contact info? : " << std::endl;
	std::cout << "first name : ";
	std::cin >> this->first_name;
	std::cout << "last name : ";
	std::cin >> this->last_name;
	std::cout << "nickname : ";
	std::cin >> this->nickname;
	std::cout << "phone number : ";
	std::cin >> this->phone_number;
	std::cout << "darkest secret : ";
	std::cin >> this->darkest_secret;
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
