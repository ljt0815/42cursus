/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:10:56 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/03 20:42:40 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CPP
# define CLAPTRAP_CPP
# include <iostream>

class ClapTrap {
	private	:
		std::string	_name;
		int	_hp;
		int	_ep;
		int	_ad;

	public	:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap &operator=(const ClapTrap &c);
		std::string	ClapTrap::getName(void) const;
		int		getHp(void) const;
		int		getEp(void) const;
		int		getAd(void) const;
		void	setName(const std::string &name);
		void	setHp(const int &hp);
		void	setEp(const int &ep);
		void	setAd(const int &ad);
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap(void);
}
