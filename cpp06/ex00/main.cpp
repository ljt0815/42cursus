#include "Casting.hpp"

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		std::cout << "Useage : ./convert NUMBER" << std::endl;
		return (1);
	}
	std::cout << Casting(av[1]) << std::endl;
	return (0);
}
