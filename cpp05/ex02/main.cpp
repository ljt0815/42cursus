/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:11:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 12:39:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat j("jitlee", 1);
	Bureaucrat g("guest", 150);
	ShrubberyCreationForm s("house");
	ShrubberyCreationForm s2("kk");
	RobotomyRequestForm r("wallE");

	
	j.signForm(s);
	j.signForm(r);
	s2 = s;
	j.executeForm(s2);
	j.executeForm(s);
	j.executeForm(r);
}
