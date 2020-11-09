#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("aaa", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n",line);
	get_next_line(fd, &line);
	printf("%s\n",line);
	return 0;
}
