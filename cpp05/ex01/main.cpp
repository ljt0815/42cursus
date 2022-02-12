/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:11:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 03:48:48 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat j("jitlee", 1);
	Bureaucrat g("guest", 150);
	Form f("administratorSignForm", 1, 1); 

	j.signForm(f);
	g.signForm(f);

	try
	{
		Form f2("0SignForm", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f2("151SignForm", 151, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << f << std::endl;
	std::cout << j << std::endl;
}
