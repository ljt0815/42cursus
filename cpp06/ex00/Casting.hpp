/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casting.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:14:02 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 15:14:16 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_HPP
# define CASTING_HPP

# include <sstream>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <iomanip>


class	Casting {
	private	:
		std::string _str;
		double	_val;
		bool	_err;
		bool	_isReal;
		Casting(void);

	public	:
		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	getDouble(void)	const;
		void	printChar(std::ostream &o);
		void	printInt(std::ostream &o);
		void	printFloat(std::ostream &o);
		void	printDouble(std::ostream &o);
		Casting(const Casting &c);
		Casting	&operator=(const Casting &c);
		Casting(std::string str);
		~Casting(void);
};
std::ostream& operator<<(std::ostream& o, Casting& c);
#endif
