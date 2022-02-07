/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:23:40 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 03:30:27 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
	_n = 0;
}

Span::Span(unsigned int n)
{
	_n = n;
}

Span::Span(const Span &origin)
{
	_n = origin._n;
	_arr = origin._arr;
}

Span &Span::operator=(const Span &origin)
{
	if (this != &origin)
	{
		_n = origin._n;
		_arr = origin._arr;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (_arr.size() == _n)
		throw FullArrayException();
	else
		_arr.push_back(num);
}

int Span::shortestSpan(void)
{
	if (_arr.size() < 2)
		throw NotSpanException();
	std::vector<int> tmp(_arr);
	std::sort(tmp.begin(), tmp.end());

	int span = 2147483647;
	for (size_t i=0; i<_arr.size() - 1; i++)
	{
		if (span > (tmp[i+1] - tmp[i]))
			span = tmp[i+1] - tmp[i];
	}
	return span;
}

int Span::longestSpan(void)
{
	if (_arr.size() < 2)
		throw NotSpanException();

	std::vector<int> tmp(_arr);
	std::sort(tmp.begin(), tmp.end());

	int span = tmp[_arr.size() - 1] - tmp[0];
	return span;
}

unsigned int Span::getN() const
{
	return (this->_n);
}

std::vector<int> Span::getArr() const
{
	return (this->_arr);
}


const char *Span::FullArrayException::what() const throw()
{
	return ("Array is Full!");
}

const char *Span::NotSpanException::what() const throw()
{
	return ("Can't find span.");
}
