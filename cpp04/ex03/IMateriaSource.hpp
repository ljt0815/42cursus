/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:20:48 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/09 04:28:07 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"

class	IMateriaSource {
	public	:
		virtual ~IMateriaSource() {}
		virtual	void learnMateria(AMateria *am) = 0;
		virtual AMateria *createMateria(std::string const & type) = 0;
};
#endif
