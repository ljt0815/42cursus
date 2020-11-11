#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int fd1;
	int fd2;
	char *line;
	int ret;
	ret = 1;
	fd = open("aaa", O_RDONLY);
	fd1 = open("bbb", O_RDONLY);
	fd2 = open("ccc", O_RDONLY);

	ret = get_next_line(fd, &line);
	printf("fd\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("fd1\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("fd2\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd, &line);
	printf("fd\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("fd1\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("fd2\n"); 
	printf("ret : %d\n", ret);
	printf("%s\n", line);
	free(line);
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return 0;
}
