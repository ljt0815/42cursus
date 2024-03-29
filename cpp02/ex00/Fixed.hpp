/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:32:58 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/20 18:54:57 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	private	:
		int	fixed_point;
		static const int fixed_bit = 8;

	public	:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed &operator=(const Fixed &f);
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
};
#endif
