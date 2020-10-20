#include <stdio.h>
#include "libft.h"

int main(void)
{
	char **c;
	c = ft_split("", '\0');
	printf("%s",c[0]);
	return 0;
}
