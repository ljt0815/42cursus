/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:30:03 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/07 23:08:18 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
class	WrongAnimal {
	protected	:
		std::string	_type;
	public		:
		void	makeSound(void) const;
		std::string	getType(void) const;
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &wa);
		WrongAnimal &operator=(const WrongAnimal &wa);
		virtual ~WrongAnimal(void);
};
#endif
