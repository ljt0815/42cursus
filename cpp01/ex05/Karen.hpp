/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:15:44 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/01 23:23:58 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	KAREN_HPP
# define KAREN_HPP
# include <iostream>

class	Karen {
	private	:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public	:
		void	complain(std::string level);

};

#endif
