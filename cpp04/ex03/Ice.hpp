/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:55:00 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 07:10:28 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria {
	public	:
		Ice(void);
		Ice(const Ice &i);
		AMateria*	clone(void) const;
		void	use(ICharacter& target);
		virtual ~Ice(void);
};
#endif
