/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:07:27 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 05:07:49 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}

	const_iterator cbegin() const
	{
		return(std::stack<T>::c.begin());
	}

	iterator end()
	{
		return (std::stack<T>::c.end());
	}

	const_iterator cend() const
	{
		return (std::stack<T>::c.end());
	}

	reverse_iterator rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}

	const_reverse_iterator crbegin() const
	{
		return (std::stack<T>::c.rbegin());
	}

	reverse_iterator rend()
	{
		return (std::stack<T>::c.rend());
	}

	const_reverse_iterator crend() const
	{
		return (std::stack<T>::c.rend());
	}
};

#endif
