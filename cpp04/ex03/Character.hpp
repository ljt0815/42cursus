/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:35:47 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 07:45:24 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class	Character : public ICharacter {
	private	:
		std::string	_name;
		AMateria *_am[4];
	public	:
		Character(void);
		Character(std::string const & name);
		std::string const & getName() const;
		void	equip(AMateria* am);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		~Character(void);
};
#endif
