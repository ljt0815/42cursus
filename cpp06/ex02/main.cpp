/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:01:23 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 15:19:58 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	Base *ret;
	srand((unsigned int)time(NULL));
	int random = rand() % 100;
	//std::cout << "random : " << random << std::endl;
	if (random < 33)
		ret = new A();
	else if (random < 66)
		ret = new B();
	else
		ret = new C();
	return (ret);
}

void	identify(Base &p)
{
	try	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &) {}
	try	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &) {}
	try	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &) {}
}

void	identify(Base *p)
{
	//std::cout << dynamic_cast<A*>(p) << std::endl;
	//std::cout << dynamic_cast<B*>(p) << std::endl;
	//std::cout << dynamic_cast<C*>(p) << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

int	main(void)
{
	Base *tmp = generate();
	identify(tmp);
	identify(*tmp);
	delete tmp;
	return (0);
}
