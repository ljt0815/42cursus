/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 05:21:36 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private	:
		const std::string	_name;
		const int	_signGrade;
		const int	_executeGrade;
		bool		_signed;
	public	:
		class	GradeTooHighException : public std::exception {
			const char* what(void) const throw();
		};
		
		class	GradeTooLowException : public std::exception {
			const char* what(void) const throw();
		};

		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSigned(void) const;
		void	beSigned(Bureaucrat &b);

		Form(void);
		Form(const Form &f);
		Form(std::string name, int signGrade, int executeGrade);
		Form &operator=(const Form &f);
		~Form(void);
};
std::ostream &operator<<(std::ostream &o, const Form &f);
#endif
