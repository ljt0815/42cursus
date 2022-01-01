/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:04:31 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/02 00:46:08 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen k;
	k.complain("debug");
	k.complain("error");
	k.complain("warning");
	k.complain("info");
	k.complain("asdfrwqer");
	return (0);
}
