#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[30];

	for(int i = 0; i < 30; i++)
		a[i] = 30;
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);
	bzero(a, 25);
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);
	return 0;
}
