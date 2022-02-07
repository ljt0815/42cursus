/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:03:32 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 03:19:29 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

class Span {
 private:
	unsigned int _n;
	std::vector<int> _arr;

 public:
	Span();
	Span(unsigned int n);
	Span(const Span &origin);
	Span &operator=(const Span &origin);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	class FullArrayException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NotSpanException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	unsigned int getN() const;
	std::vector<int> getArr() const;
};

#endif

