/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:57:27 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 01:08:26 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private	:
		Brain	*b;
	public	:
		void	makeSound(void) const;
		Dog(void);
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog(void);
};
#endif
