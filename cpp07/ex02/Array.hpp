/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:15:43 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 17:22:45 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class	Array {
	private	:
		T				*_arr;
		unsigned int	_len;

	public	:
		class	SegFault : public std::exception {
			const char * what(void) const throw()
			{
				return ("Segfault!! Access non allocated memory");
			}
		};

		unsigned int	getLen(void) const
		{
			return (_len);
		}

		Array(void)
		{
			_len = 0;
			_arr = new T[_len];
		}

		Array(unsigned int a)
		{
			_len = a;
			_arr = new T[_len];
		}

		Array(const Array &a)
		{
			_len = a._len;
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_arr[i] = a._arr[i];
		
		}

		Array &operator=(const Array &a)
		{
			delete [] _arr;
			if (this != &a)
			{
				_len = a._len;
				_arr = new T[_len];
				for (unsigned int i = 0; i < _len; i++)
					_arr[i] = a._arr[i];
			}
			return (*this);
		}

		T &operator[](unsigned int index) const
		{
			if (_len <= index)
				throw SegFault();
			return (_arr[index]);
		}

		~Array(void)
		{
			delete [] _arr;
		}
};
#endif
