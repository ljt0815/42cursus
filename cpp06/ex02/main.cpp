#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *ret;
	srand((unsigned int)time(NULL));
	int random = rand() % 100;
	if (random < 33)
		ret = new A();
	else if (random < 66)
		ret = new B();
	else
		ret = new C();
	return (ret);
}

int	main(void)
{
	Base *tmp = generate();
	std::cout << tmp->getType() << std::endl;
	return (0);
}
