/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:49:25 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/30 01:28:11 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
	private	:
		std::string name;
		void		announce(void);

	public	:
		Zombie(std::string name);
		static	Zombie*		newZombie(std::string name);
		static	void		randomChump(std::string name);
		~Zombie(void);
};

#endif
