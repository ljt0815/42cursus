/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:31:35 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/31 00:39:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
	private	:
		std::string name;
		Weapon		*w;
	public	:
		HumanB(std::string name);
		void	setWeapon(Weapon &w);
		void	attack(void);
};
#endif
