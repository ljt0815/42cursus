/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:58:41 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 04:37:20 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class	Cat : public Animal {
	private	:
		Brain	*_b;
	public	:
		std::string *tmp;
		void	makeSound(void) const;
		Cat(void);
		Cat(const Cat &c);
		Cat	&operator=(const Cat &c);
		~Cat(void);
};
#endif
