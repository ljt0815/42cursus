/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:38:36 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 02:16:53 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n)
{
	_n = n;
}

void	Span::print(void)
{
	for (unsigned long i = 0; i < _arr.size(); i++)
		std::cout << _arr[i] << " ";
	std::cout << std::endl;
}

void	Span::addNumber(int num)
{
	if (_arr.size() >= _n)
		throw ArrayIsFullException();
	_arr.push_back(num);
}

void	Span::addNumber(std::string str)
{
	std::string buf;
	std::istringstream iss(str);
	while (getline(iss, buf, ' '))
	{
		if (_arr.size() >= _n)
			throw ArrayIsFullException();
		_arr.push_back(atoi(buf.c_str()));
	}
}

void	Span::addRandomNumber(int len)
{
	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		if (_arr.size() >= _n)
			throw ArrayIsFullException();
		 int random = (long long)(rand() * (i + 7)) % 100000;
		 if (random < 0)
			 random *= -1;
		_arr.push_back(random);
	}
}

int		Span::shortestSpan(void)
{
	int span;

	if (_arr.size() <= 1)
		throw HasNotSpanException();
	std::vector<int> tmp(_arr);
	std::sort(tmp.begin(), tmp.end());
	span = tmp[1] - tmp[0];
	for (unsigned long i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < span)
			span = tmp[i + 1] - tmp[i];
	}
	return (span);
}

int		Span::longestSpan(void)
{
	int span;

	if (_arr.size() <= 1)
		throw HasNotSpanException();
	std::vector<int> tmp(_arr);
	std::sort(tmp.begin(), tmp.end());
	span = tmp[_arr.size() - 1] - tmp[0];
	return (span);
}

Span::Span(const Span &s)
{
	_n = s._n;
	_arr.assign(s._arr.begin(), s._arr.end());
}

Span &Span::operator=(const Span &s)
{
	if (this != &s)
	{
		if (_arr.size() != 0)
			_arr.clear();
		_n = s._n;
		_arr.assign(s._arr.begin(), s._arr.end());
	}
	return (*this);
}

Span::~Span(void)
{
	_arr.clear();
}
