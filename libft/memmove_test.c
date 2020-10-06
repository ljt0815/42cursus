#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char array[10];

	bzero(array, sizeof(array));
	strcpy(array, "test");

	printf("original : %s\n", array);

	ft_memmove(array, array+2, strlen("test"));

	printf("after memmove : %s\n", array);

	return 0;
}
