/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:24:36 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/07 06:41:49 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
class	Animal {
	protected	:
		std::string	_type;
	public		:
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
		Animal(void);
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal(void);
};
#endif
