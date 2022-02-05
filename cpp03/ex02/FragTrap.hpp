/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:02:26 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 03:23:24 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# define F_HP 100
# define F_EP 100
# define F_AD 30

class FragTrap : public ClapTrap {
	public	:
		void	attack(std::string const & target);
		void	highFivesGuys(void);
		FragTrap &operator=(const FragTrap &f);
		FragTrap(const FragTrap &f);
		FragTrap(void);
		FragTrap(std::string name);
		virtual ~FragTrap(void);
};
#endif
