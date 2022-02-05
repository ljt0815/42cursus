/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:22:52 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 01:48:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private	:
		std::string	_name;

	public	:
		void	whoAmI(void);
		void	attack(std::string const & target);
		std::string	getName(void) const;
		DiamondTrap &operator=(const DiamondTrap &d);
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
};
#endif
