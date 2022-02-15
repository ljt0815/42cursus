#include "iter.hpp"

int main(void)
{
	int i[4] = { 4, 3, 2, 1};
	double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string s[3] = {"you", "me", "we"};

	iter(i, sizeof(i) / sizeof(int), print);
	iter(d, sizeof(d) / sizeof(double), print);
	iter(s, sizeof(s) / sizeof(std::string), print);
	return (0);
}
