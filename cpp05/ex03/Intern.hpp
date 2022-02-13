/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:13:05 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 15:30:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern {
	public	:
		class	NotFoundNameException : public std::exception
		{
			const char* what(void) const throw();
		};

		Form* makeForm(std::string name, std::string target);

		Intern(void);
		Intern &operator=(const Intern &i);
		Intern(const Intern &i);
		~Intern(void);
};

#endif
