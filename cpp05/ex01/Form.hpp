/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/12 04:23:02 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>

class	Form {
	private	:
		const std::string	_name;
		const int	_signGrade;
		const int	_excuteGrade;
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
		int getExcuteGrade(void) const;
		bool getSigned(void) const;
		void	beSigned(Bureaucrat &b);

		Form(void);
		Form(const Form &f);
		Form(std::string name, int signGrade, int excuteGrade);
		Form &operator=(const Form &f);
		~Form(void);
};
#endif
