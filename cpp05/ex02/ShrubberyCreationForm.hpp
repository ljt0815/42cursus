/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:34:37 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 11:44:56 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>

#include "Form.hpp"

class	ShrubberyCreationForm : public Form {
	private	:
		ShrubberyCreationForm(void);

	public	:
		void	execute(Bureaucrat const &b) const;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &s);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		~ShrubberyCreationForm(void);
};
#endif
