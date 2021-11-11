/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:01:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/12 00:18:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	int i;

	i = -1;
	this->len = 0;
	while (++i < 8)
		this->idx[i] = -1;
}

void	PhoneBook::p_add()
{
	Contact	contact;
	contact.fill_contact(len + 1);
	this->contacts[len % 8] = contact;
	idx[len % 8] = len + 1;
	this->len++;
}

void	PhoneBook::print_contact()
{
	int i;
	int	index;

	std::cout << "Enter index : ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Input Error!" << std::endl;
		return ;
	}
	i = -1;
	while (++i < 8)
	{
		if (idx[i] == index)
		{
			contacts[i].print_contact();
			break ;
		}
	}
	if (i == 8)
		std::cout << "Wrong index!" << std::endl;
}

void	PhoneBook::print_contact_list()
{
	int	len;
	int	index;

	if (this->len > 8)
		len = 8;
	else
		len = this->len;
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	index = -1;
	while (++index < len)
		contacts[index].print_short_info();
}

void	PhoneBook::p_search()
{
	if (this->len == 0)
		std::cout << "PhoneBook is Empty" << std::endl;
	else
	{
		PhoneBook::print_contact_list();
		PhoneBook::print_contact();
	}
}
