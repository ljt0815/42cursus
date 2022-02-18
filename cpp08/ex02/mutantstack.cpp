/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:52:05 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 14:25:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : MutantStack<T>::stack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &m) : MutantStack<T>::stack(m)
{

}

template <typename T>
MutantStack<T>::~MutantStack(void)
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &m)
{
	if (this != &m)
	{
		MutantStack<T>::stack::operator=(m);
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return (this->c.rend());
}
