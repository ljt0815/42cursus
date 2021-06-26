#include <stdio.h>

int main(void)
{
	char a = 127;

	printf("before : %d\n", a);
	a >>= 1;
	printf("after : %d\n", a);
	/*
	printf("숫자 : %d\n", a);
	printf("%d\n", a & 1);
	printf("%d\n", a & 2);
	printf("%d\n", a & 4);
	printf("%d\n", a & 8);
	printf("%d\n", a & 16);
	printf("%d\n", a & 32);
	printf("%d\n", a & 64);
	printf("%d\n", a & 128);
	*/
}
