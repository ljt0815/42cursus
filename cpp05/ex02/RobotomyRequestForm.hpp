/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:54:55 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 15:59:48 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
#include "Form.hpp"

class	RobotomyRequestForm : public Form {
	private	:
		RobotomyRequestForm(void);
	public	:
		void	execute(Bureaucrat const &b) const;
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
		RobotomyRequestForm(const RobotomyRequestForm &r);
		virtual ~RobotomyRequestForm(void);
};
#endif
