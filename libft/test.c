#include <stdio.h>
#include "libft.h"

int main(void)
{
	char **a;
	a = ft_split("", '\0');
	printf("%s", a[0]);

	return 0;
}
