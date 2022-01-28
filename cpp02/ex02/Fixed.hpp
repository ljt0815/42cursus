/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:37:24 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/28 17:51:27 by jitlee           ###   ########.fr       */
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
		Fixed operator+(const Fixed &f);
		Fixed operator-(const Fixed &f);
		Fixed operator*(const Fixed &f);
		Fixed operator/(const Fixed &f);
		Fixed operator++();
		const Fixed operator++(int);
		Fixed operator--();
		const Fixed operator--(int);
		bool operator<(const Fixed &f) const;
		bool operator>(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
};
std::ostream& operator<<(std::ostream& o, const Fixed& f);
#endif
