#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int ret;

	ret = 1;
	fd = open("aaa", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return 0;
}
