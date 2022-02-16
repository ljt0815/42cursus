#include "Array.hpp"

int main(void)
{
	Array<int> a(10);

	for (int i = 0; i < a.getLen(); i++)
	{
		std::cout << a[i] << std::endl;
	}
}
