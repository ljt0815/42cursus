/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:19:33 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 14:21:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Cure : public AMateria {
	public	:
		Cure(void);
		Cure(std::string const & type);
		Cure(const Cure &c);
		Cure &operator=(const Cure &c);
		AMateria*	clone(void) const;
		void	use(ICharacter& target);
		virtual ~Cure(void);
};
#endif
