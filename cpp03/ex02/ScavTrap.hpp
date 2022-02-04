/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:39:36 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/05 04:26:54 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		void	guardGate(void);
		void	attack(std::string const & target);
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
};
#endif
