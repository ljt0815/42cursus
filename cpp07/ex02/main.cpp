#include "Array.hpp"

int main(void)
{
	Array<int> a(10);

	try {
		for (unsigned int i = 0; i < a.getLen(); i++)
			std::cout << a[i] << std::endl;
		for (unsigned int i = 0; i < a.getLen(); i++)
			a[i] = i;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		a[10] = 1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
