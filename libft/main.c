#include <stdio.h>
#include "libft.h"

int main(void)
{
	char a[30];
    char b[20];

	for(int i = 0; i < 30; i++)
		a[i] = i;
    puts("-------a array--------\n");
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);
	ft_bzero(a, 25);
    puts("-------after ft_bzero(a, 25);--------\n");
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);

    puts("- b[] adrress -");
    printf("%p\n",b);
    puts("after ft_memset(b, 65, sizeof(b))");
    puts("- ft_memset return value -");
    printf("%p\n",ft_memset(b, 65, sizeof(b)));
	for(unsigned int i = 0; i < (sizeof(b)/sizeof(char)); i++)
	{
		printf("b[%d] = %c\n", i, b[i]);
	}
	return 0;
}
