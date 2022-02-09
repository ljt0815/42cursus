/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:06 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 15:37:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class	Bureaucrat : std::exception {
	private	:
		std::string	_name;
		int			_grade;

	public	:
		class	GradeTooHighException : public std::exception {
			public	:
				const	char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public :
				const	char* what(void) const throw();
		};
		const	std::string getName(void) const;
		const	int			getGrade(void) const;
		int	incrementGrade(void);
		int	decrementGrade(void);
		Bureaucrat(void);
		Bureaucrat(const Bureacrat &b);
		Bureaucrat &operator=(const	Bureacrat &b);
		~Bureaucrat(void);
};
#endif
