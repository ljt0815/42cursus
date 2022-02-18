/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:52:16 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/18 14:27:23 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class	MutantStack	: public std::stack<T> {
	public	:
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		MutantStack(void);
		MutantStack(const MutantStack &m);
		MutantStack& operator=(const MutantStack &m);
		~MutantStack(void);
};
#endif
