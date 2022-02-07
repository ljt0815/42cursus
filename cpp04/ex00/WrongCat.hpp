/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:02:21 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 06:41:01 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
class	WrongCat : public WrongAnimal {
	public	:
		void	makeSound(void) const;
		WrongCat(void);
		WrongCat(const WrongCat &wc);
		WrongCat	&operator=(const WrongCat &wc);
		virtual ~WrongCat(void);
};
#endif
