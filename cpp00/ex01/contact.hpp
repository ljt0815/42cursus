/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:58:00 by jitlee            #+#    #+#             */
/*   Updated: 2021/11/12 00:17:44 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCAT_HPP
# define CONCAT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class	Contact {
	private:
		int			idx;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string darkest_secret;
	public:
		void		fill_contact(int idx);
		void		print_contact();
		std::string	print_field(std::string field);
		void		print_short_info();
};

#endif
