/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:02:20 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/29 11:42:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
	private	:
		std::string str;
	public	:
		Weapon(std::string str);
		const std::string	&getType(void) const;
		void		setType(std::string str);
};

#endif
