/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:02:45 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/11 22:58:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"

class	PhoneBook {
	private	:
		Contact	contacts[8];
		int		idx[8];
		int		len;
	public	:
		PhoneBook();
		void	p_add();
		void	p_search();
		void	print_contact();
		void	print_contact_list();
};

#endif
