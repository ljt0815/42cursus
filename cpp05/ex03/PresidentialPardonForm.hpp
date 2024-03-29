/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:51:37 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/13 16:00:26 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form {
	private	:
		PresidentialPardonForm(void);
	public	:
		void	execute(Bureaucrat const &b) const;
		static Form	*createForm(std::string target);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		virtual ~PresidentialPardonForm(void);
};
#endif
