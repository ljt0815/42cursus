#include <stdio.h>
#include "libft.h"

int main(void)
{
	char a[30];
    char b[30];

    puts("*********** ft_bzero TEST ****************");
	for(int i = 0; i < 30; i++)
		a[i] = i;
    puts("-------a array--------\n");
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);
	ft_bzero(a, 25);
    puts("-------after ft_bzero(a, 25);--------\n");
	for(int i = 0; i < 30; i++)
		printf("a[%d] = %d\n",i, a[i]);

    puts("*********** ft_memset TEST ****************");
    puts("- b[] adrress -");
    printf("%p\n",b);
    puts("after ft_memset(b, 65, sizeof(b))");
    puts("- ft_memset return value -");
    printf("%p\n",ft_memset(b, 65, sizeof(b)));
	for(unsigned int i = 0; i < (sizeof(b)/sizeof(char)); i++)
	{
		printf("b[%d] = %c\n", i, b[i]);
	}

    puts("*********** ft_memcpy TEST ****************");
    printf("b[1] = 1;\n");
    printf("b[5] = 12;\n");
    printf("b[7] = 13;\n");
    printf("b[9] = 16;\n");
    printf("b[11] = 19;\n");
    b[1] = 1;
    b[5] = 12;
    b[7] = 13;
    b[9] = 16;
    b[11] = 19;
    printf("ft_memcpy(a,b,15);\n");
    ft_memcpy(a,b,15);
    for(int i = 0; i < 15; i++)
		printf("a[%d] = %d\n",i, a[i]);
	return 0;
}
