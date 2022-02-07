/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:50:43 by seuyu             #+#    #+#             */
/*   Updated: 2022/02/08 05:09:24 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class CannotFindTargetException : public std::exception
{
	const char *what() const throw()
	{
		return ("Cannot find target!!");
	}
};

template <typename T>
typename T::iterator easyfind(T container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
	{
		throw CannotFindTargetException();
	}
	return it;
}



#endif
