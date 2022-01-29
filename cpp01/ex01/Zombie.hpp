/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:49:25 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/29 11:02:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstring>

class Zombie {
	private	:
		std::string name;

	public	:
		Zombie(void);
		Zombie(std::string name);
		void				setName(std::string name);
		void				announce(void);
		~Zombie(void);
};

Zombie		*zombieHorde(int N, std::string name);
#endif
