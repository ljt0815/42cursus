/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:49:25 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/29 11:13:10 by jitlee           ###   ########.fr       */
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
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);
#endif
