/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:55:00 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 14:22:03 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Ice : public AMateria {
	public	:
		Ice(void);
		Ice(std::string const & type);
		Ice(const Ice &i);
		Ice &operator=(const Ice &i);
		AMateria*	clone(void) const;
		void	use(ICharacter& target);
		virtual ~Ice(void);
};
#endif
