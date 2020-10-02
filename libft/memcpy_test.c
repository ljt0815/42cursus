#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[20];
	char b[20];

	for (int i = 0; i < 20; i++)
		a[i] = i;
	for (int i = 0; i < 20; i++)
		printf("a[%d] = %d\n",i, a[i]);

	memcpy(b, a, 10);
	for (int i = 0; i < 20; i++)
		printf("b[%d] = %d\n",i, b[i]);

	return 0;
}
