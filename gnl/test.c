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
	a = get_next_line(fd, &line);
	printf("%d\n", a);
	printf("%s\n",line);
	a = get_next_line(fd, &line);
	printf("%d\n", a);
	printf("%s\n",line);
	a = get_next_line(fd, &line);
	printf("%d\n", a);
	printf("%s\n",line);
	
	return 0;
}
