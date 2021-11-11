/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:01:36 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/12 03:43:14 by jitlee           ###   ########.fr       */
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
	contact.fill_contact(this->len + 1);
	this->contacts[this->len % 8] = contact;
	idx[this->len % 8] = this->len + 1;
	this->len++;
}

int		PhoneBook::my_atoi(std::string str)
{
	int i;
	int	ret;

	ret = 0;
	i = -1;
	if ((int)str.length() == 0)
		return (-1);
	while (++i < (int)str.length())
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
	if (i != (int)str.length())
		return (-1);
	i = -1;
	while (++i < (int)str.length())
		ret = (ret * 10) + (str[i] - '0');
	return (ret);
}

void	PhoneBook::print_contact()
{
	int 		i;
	int			index;
	std::string	tmp;

	std::cout << "Enter index : ";
	if (!std::getline(std::cin, tmp))
		return ;
	i = -1;
	index = my_atoi(tmp);
	if (index == -1)
	{
		std::cout << "INDEX IS ONLY NUMBER" << std::endl;
		return ;
	}
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
