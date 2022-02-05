/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:10:56 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/06 01:11:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CPP
# define CLAPTRAP_CPP
# include <iostream>

# define C_HP	10
# define C_EP	10
# define C_AD	0

class ClapTrap {
	private	:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_hpMax;
		unsigned int	_ep;
		unsigned int	_ad;

	public	:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap &operator=(const ClapTrap &c);
		std::string	getName(void) const;
		unsigned int	getHp(void) const;
		unsigned int	getHpMax(void) const;
		unsigned int	getEp(void) const;
		unsigned int	getAd(void) const;
		void	setName(const std::string &name);
		void	setHp(const int &hp);
		void	setEp(const int &ep);
		void	setAd(const int &ad);
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		virtual ~ClapTrap(void);
};
#endif
