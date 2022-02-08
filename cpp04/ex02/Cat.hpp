/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:58:41 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 06:31:35 by jitlee           ###   ########.fr       */
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
		void	makeSound(void) const;
		Cat(void);
		Cat(const Cat &c);
		std::string	getBrainStr(int i) const;
		void	setBrainStr(std::string tmp, int i);
		Cat	&operator=(const Cat &c);
		void	brainScan(void);
		virtual ~Cat(void);
};
#endif
