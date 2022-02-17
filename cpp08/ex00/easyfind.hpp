/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:54:01 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/17 23:39:54 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &t, int target)
{
	typename T::iterator it = std::find(t.begin(), t.end(), target);
	if (it == t.end())
	{
		throw std::runtime_error("iteratorException!!");
	}
	return it;
}

#endif
