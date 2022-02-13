/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:34:09 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 11:31:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <typeinfo>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	chkExecute(b);
	std::ofstream file;
	file.open("<" + getName() + ">_shrubbery");
	if (!file.is_open() || !file.good())
		throw FileErrorException();
	std::string tree = "          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n";
	file.write(tree.c_str(), tree.length());
	file.close();
}

void	ShrubberyCreationForm::test(int val)
{
	std::cout << val << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	Form::operator=(s);
	std::cout << "ShrubberyCreationForm assign operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form(s)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
