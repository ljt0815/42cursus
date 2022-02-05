/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:39:36 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 01:12:59 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# define S_HP	100
# define S_EP	50
# define S_AD	20

class ScavTrap : public ClapTrap {
	public :
		void	guardGate(void);
		void	attack(std::string const & target);
		ScavTrap &operator=(const ScavTrap &s);
		ScavTrap(void);
		ScavTrap(std::string name);
		virtual ~ScavTrap(void);
};
#endif
