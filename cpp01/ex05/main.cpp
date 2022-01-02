/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:04:31 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/03 06:03:32 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen k;
	k.complain("DEBUG");
	k.complain("ERROR");
	k.complain("WARNING");
	k.complain("INFO");
	k.complain("asdfrwqer");
	return (0);
}
