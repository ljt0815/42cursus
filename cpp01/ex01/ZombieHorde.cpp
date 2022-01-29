/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:49:22 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/29 11:02:22 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *tmp = new Zombie[N];
	for (int i = 0; i < N; i++)
		tmp[i].setName(name + std::to_string(i + 1));
	return (tmp);
}
