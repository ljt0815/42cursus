/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:38:46 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 01:56:38 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <cstdlib>
#include <sstream>
#include <ctime>

class	Span {
	private	:
		unsigned int _n;
		std::vector<int> _arr;
		Span(void) {};
	public	:
		class	ArrayIsFullException : public std::exception {
			const char *what(void) const throw()
			{
				return ("[EXCEPTION] Array is Full!!");
			}
		};
		class	HasNotSpanException : public std::exception {
			const char *what(void) const throw()
			{
				return ("[EXCEPTION] Has Not Span!!");
			}
		};
		void	print(void);
		void	addNumber(int num);
		void	addNumber(std::string str);
		void	addRandomNumber(int len);
		int		shortestSpan(void);
		int		longestSpan(void);
		Span(unsigned int n);
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span(void);
};
#endif
