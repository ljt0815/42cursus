/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:41:21 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 15:31:17 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &i)
{
	(void)i;
	return (*this);
}

Intern::Intern(const Intern &i)
{
	(void)i;
}

Intern::~Intern(void)
{
	std::cout << "Intern destuctor called" << std::endl;
}

const char *Intern::NotFoundNameException::what(void) const throw()
{
	return ("[Intern]NotFoundNameForm!!");
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	Form	*(*f[3])(std::string) = {&PresidentialPardonForm::createForm, &RobotomyRequestForm::createForm, &ShrubberyCreationForm::createForm};
	std::string	n[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	int i = 0;
	while (name != n[i] && i < 3)
		i++;
	switch (i)
	{
		case 0:
			return (*(f[0]))(target);
		case 1:
			return (*(f[1]))(target);
		case 2:
			return (*(f[2]))(target);
		default :
			throw NotFoundNameException();
	}
}
