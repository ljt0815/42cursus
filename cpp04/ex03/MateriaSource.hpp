/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:13:04 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 10:44:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {
	private	:
		AMateria* _am[4];

	public	:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ms);
		MateriaSource &operator=(const MateriaSource &ms);
		AMateria* createMateria(std::string const & type);
		void	learnMateria(AMateria *am);
		virtual	~MateriaSource();
};
#endif
