#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int a;

	fd = open("aaa", O_RDONLY);
	a = get_next_line(fd, &line);
	printf("%d\n", a);
	printf("%s\n",line);
	free(line);
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return 0;
}
