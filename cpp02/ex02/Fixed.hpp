/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:37:24 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/26 21:06:45 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
	private	:
		int	fixed_point;
		static const int fixed_bit = 8;

	public	:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed &operator=(const Fixed &f);
		bool operator<(const Fixed &f) const;
		bool operator>(const Fixed &f) const;
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
};
std::ostream& operator<<(std::ostream& o, const Fixed& f);
#endif
