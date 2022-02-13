/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:11:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 15:41:53 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat j("jitlee", 1);
	Form*	rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	std::cout << *rrf << std::endl;
	j.signForm(*rrf);
	j.executeForm(*rrf);
	delete rrf;
	rrf = NULL;
	rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	std::cout << *rrf << std::endl;
	j.signForm(*rrf);
	j.executeForm(*rrf);
	delete rrf;
	rrf = NULL;
	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	std::cout << *rrf << std::endl;
	j.signForm(*rrf);
	j.executeForm(*rrf);
	delete rrf;
	rrf = NULL;
	try
	{
		rrf = someRandomIntern.makeForm("blablabla", "Bender");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << rrf << std::endl;
}
