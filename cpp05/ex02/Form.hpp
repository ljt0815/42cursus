/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 10:26:53 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private	:
		const std::string	_target;
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

		class	NotSignedException : public std::exception {
			const char* what(void) const throw();
		};

		class	FileErrorException : public std::exception {
			const char* what(void) const throw();
		};

		std::string getTarget(void) const;
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSigned(void) const;
		void	beSigned(Bureaucrat &b);
		void	chkExecute(const Bureaucrat &b) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		Form(void);
		Form(const Form &f);
		Form(std::string type, std::string name, int signGrade, int executeGrade);
		Form &operator=(const Form &f);
		~Form(void);
};
std::ostream &operator<<(std::ostream &o, const Form &f);
#endif
