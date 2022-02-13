/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:11:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 14:06:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat j("jitlee", 1);
	Bureaucrat g146("g146", 146);
	Bureaucrat g72("g72", 72);
	Bureaucrat g25("g25", 25);
	ShrubberyCreationForm s("house");
	ShrubberyCreationForm s2("kk");
	ShrubberyCreationForm s3("kk");
	RobotomyRequestForm r("wallE");
	PresidentialPardonForm p("ppf");

	j.signForm(s);
	j.signForm(r);
	j.signForm(p);
	s2 = s;
	j.executeForm(s2);
	j.executeForm(s);
	j.executeForm(r);
	j.executeForm(p);

	g146.signForm(s3);
	g146.incrementGrade();
	g146.signForm(s3);
	g146.executeForm(s3);
	for (int i = 0; i < 8; i++)
		g146.incrementGrade();
	g146.executeForm(s3);
}
