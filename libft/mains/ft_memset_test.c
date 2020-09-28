#include <stdio.h>

void *ft_memset(void *b, int c, size_t len);

int main(void)
{
	char a[20];

	printf("%p",ft_memset(a, 65, sizeof(a)));

	for(unsigned int i = 0; i < (sizeof(a)/sizeof(char)); i++)
	{
		printf("%c\n", a[i]);
	}
	printf("%p",a);

	return 0;
}
