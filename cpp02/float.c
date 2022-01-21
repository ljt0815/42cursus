#include <stdio.h>

int main(void)
{
	void *b;
	float f = 7.625f;
	
	b = &f;

	for (int i = 31; i >= 0; i--)
	{
		int bit;
		if ((*((int *)b) & 1<<i) == 0)
			bit = 0;
		else
			bit = 1;
		printf("%d", bit);
	}
	return (0);
}
