#include <stdio.h>
#include "libft.h"
#include "mlx.h"

int main(void)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	printf("%p", mlx_ptr);
	return 0;
}
