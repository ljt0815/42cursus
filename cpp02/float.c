#include <stdio.h>

int main(void)
{
	void *b;
	float f;
	
	while(1)
	{
		printf("input float number : \n");
		scanf("%f", &f);
		b = &f;

		for (int i = 31; i >= 0; i--)
		{
			int bit;
			if ((*((int *)b) & 1<<i) == 0)
				bit = 0;
			else
				bit = 1;
			printf("%d", bit);
			if (i == 31 || i == 23)
				printf(" ");
		}
		printf("\n");
	}
	return (0);
}
