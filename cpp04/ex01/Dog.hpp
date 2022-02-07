/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:57:27 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 06:31:43 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private	:
		Brain	*_b;
	public	:
		void	makeSound(void) const;
		Dog(void);
		Dog(const Dog &d);
		std::string	getBrainStr(int i) const;
		void	setBrainStr(std::string tmp, int i);
		Dog &operator=(const Dog &d);
		void	brainScan(void);
		virtual ~Dog(void);
};
#endif
