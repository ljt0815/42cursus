/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:46:47 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 09:48:38 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class	ICharacter;

class	AMateria
{
	protected	:
		std::string _type;
	public		:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &am);
		AMateria &operator=(const AMateria &am);
		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual	~AMateria(void);
};
#endif
