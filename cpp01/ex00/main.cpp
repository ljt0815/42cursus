/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:20:07 by jitlee            #+#    #+#             */
/*   Updated: 2021/12/30 01:26:30 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*tmp;

	tmp = Zombie::newZombie("heapheap");
	Zombie::randomChump("stackstack");
	delete tmp;
	return (0);
}
