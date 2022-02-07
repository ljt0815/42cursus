/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:50:30 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 01:39:13 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <cstring>

class	Brain {
	private	:
		std::string _s[100];
	public	:
		Brain(void);
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		~Brain(void);
};
#endif
