/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:00 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/10 14:19:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("GradeTooHigh!!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("GradeTooLow!!");
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

int	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	std::cout << "incrementGrade" << std::endl;
	_grade -= 1;
	return (_grade);
}

int	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << "decrementGrade" << std::endl;
	_grade += 1;
	return (_grade);
}

Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat name, grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b.getName()), _grade(b.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
	{
		*(const_cast<std::string *>(&_name)) = b.getName();
		_grade = b.getGrade();
	}
	std::cout << "Bureaucrat assign operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	return o << b.getName() << "'s grade ["<< b.getGrade() << "]";
}
