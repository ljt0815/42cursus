/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:06 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/10 10:21:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

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
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const	Bureaucrat &b);
		~Bureaucrat(void);
};
#endif
