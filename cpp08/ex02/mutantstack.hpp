/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:52:16 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 12:36:07 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack	: public std::stack<T> {
	public	:
		typename std::stack<T>::container_type::iterator begin(void)
		{
			return (this->c.begin());
		}

		typename std::stack<T>::container_type::iterator end(void)
		{
			return (this->c.end());
		}

		typename std::stack<T>::container_type::reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		typename std::stack<T>::container_type::reverse_iterator rend(void)
		{
			return (this->c.rend());
		}

		MutantStack(void) {}
		MutantStack(const MutantStack &m) { *this = m; }
		MutantStack& operator=(const MutantStack &m)
		{
			std::stack<T>::operator=(m);
			return (*this);
		}
		~MutantStack(void) {}
};
#endif
