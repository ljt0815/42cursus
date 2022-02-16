/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:17:04 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 15:17:27 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

struct Data {
	std::string	name;
	int			age;
};

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main(void)
{
	Data guest1 = {"guest1", 23};
	Data guest2 = {"guest2", 29};

	uintptr_t p1 = serialize(&guest1);
	uintptr_t p2 = serialize(&guest2);
	
	Data *p = deserialize(p1);
	std::cout << p->age << std::endl;
	p = deserialize(p2);
	std::cout << p->age << std::endl;
}
