/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:57:27 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 06:41:57 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
class	Dog : public Animal {
	public	:
		void	makeSound(void) const;
		Dog(void);
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		virtual ~Dog(void);
};
#endif
