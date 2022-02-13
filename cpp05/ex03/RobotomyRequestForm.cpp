/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:54:45 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 15:26:21 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	chkExecute(b);
	srand((unsigned int)time(NULL));
	std::string drill =	"      -@@@@@@@@@@@@@@@@$               \n\
      @;#               -@@@@           \n\
    !=  #               -@@@@!!*,       \n\
    @.  #               --  @   @$$$$$$ \n\
    @.  #               -$==@   @       \n\
    #.  #               --  #!**;       \n\
    @.  #               --  @           \n\
    -@: #               -@@@=           \n\
      ,@@     $#########@               \n\
        @    -**,                       \n\
       ;.    @ *,                       \n\
       @    !###.   .@#@    .           \n\
      !-   .=       =  =-   #           \n\
      #    @        =  *:   #           \n\
     =     #        =  *:   $           \n\
     #     #        =  *:   #           \n\
     @@@@@@@@@      =  *:   #           \n\
     @       #!!    =  *!   #           \n\
     @       # =@@@@$   @##$@           \n\
     @@@@@@@@@!!\n";
	if (((rand() % 100) + 1) <= 50)
	{
		std::cout << drill << "<" << getTarget() << "> has been robotomized successfully 50%% of the time." << std::endl;
	}
	else
	{
		std::cout << "<" << getTarget() << "> has been robotomized failly 50%% of the time." << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, "RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	Form::operator=(r);
	std::cout << "RobotomyRequestForm assign operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form(r)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

Form	*RobotomyRequestForm::createForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}
