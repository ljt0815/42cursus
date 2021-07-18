#include <stdio.h>
#include "libft.h"

typedef struct {
	char *buf;
	char ch;
	int len;
	int pid;
	int n;
}	t_buf;

typedef struct {
	t_buf	buf[100];
	int		client_num;
}	t_dat;

int main(void)
{
	t_dat a;
	
	a.buf[0].buf = malloc(50);
	a.buf[0].pid = 50;
	a.buf[0].n = 26;
	ft_strlcpy(a.buf[0].buf, "dlrpakwsi", 10);
	ft_memcpy(&a.buf[1], &a.buf[0], sizeof(t_buf));
	printf("1 : %s", a.buf[0].buf);
	printf("2 : %s", a.buf[1].buf);
	printf("2 : %d", a.buf[1].pid);
	printf("2 : %d", a.buf[1].n);
}
