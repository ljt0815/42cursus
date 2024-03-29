/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:03:22 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 05:20:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("[Form]GradeTooHigh!!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("[Form]GradeTooLow!!");
}

std::string Form::getName(void) const
{
	return (_name);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

Form::Form(void) :  _name("unnamed"), _signGrade(150), _executeGrade(150), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _signed(false)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form string, int, int constructor called" << std::endl;
}

Form::Form(const Form &f) : _name(f.getName()), _signGrade(f.getSignGrade()), _executeGrade(f.getExecuteGrade())
{
	_signed = f.getSigned();
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &f)
{
	if (this != &f)
	{
		*(const_cast<std::string *>(&_name)) = f.getName();
		*(const_cast<int *>(&_signGrade)) = f.getSignGrade();
		*(const_cast<int *>(&_executeGrade)) = f.getExecuteGrade();
		_signed = f.getSigned();
	}
	std::cout << "Form assign operater called" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << "'s signGrade ["<< f.getSignGrade() << "] executeGrade [" << f.getExecuteGrade() << "] signed [";
	if (f.getSigned())
		o << "true";
	else
		o << "false";
	return o << "]";
}
