#include <iostream>
#include "Casting.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Useage : ./convert NUMBER" << std::endl;
		return (1);
	}
	Casting c(av[1]);
	std::cout << c << std::endl;
	return (0);
}
