/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:06 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 10:16:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class	Form;

class	Bureaucrat {
	private	:
		const std::string	_name;
		int					_grade;

	public	:
		class	GradeTooHighException : public std::exception {
			public	:
				const	char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public :
				const	char* what(void) const throw();
		};
		std::string getName(void) const;
		int			getGrade(void) const;
		int	incrementGrade(void);
		int	decrementGrade(void);
		void	signForm(Form &f);
		void	executeForm(Form const &f);
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const	Bureaucrat &b);
		~Bureaucrat(void);
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);
#endif