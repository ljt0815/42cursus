/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:02:20 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 02:37:56 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
	private	:
		std::string str;
		Weapon(void);
	public	:
		Weapon(std::string str);
		const std::string	&getType(void);
		void		setType(std::string str);
};

#endif
