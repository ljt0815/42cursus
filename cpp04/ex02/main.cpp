/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:03:34 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/08 09:11:03 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* a[20];
	Dog *d;
	//Animal aa;
	
	for (int i = 0; i < 10; i++)
		a[i] = new Cat();
		//a[i] = new Animal();
	for (int i = 10; i < 20; i++)
		a[i] = new Dog();

	d = dynamic_cast<Dog *>(a[19]);
	d->setBrainStr("asdfasdfaf", 3);

	d->brainScan();
	Dog d4 = *d;
	std::cout << "-----------------------------------------------" << std::endl;
	delete a[19];
	d4.brainScan();
	for (int i = 0; i < 19; i++)
		delete a[i];
}
