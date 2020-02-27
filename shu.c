#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 8
#define min 1
#define N 8

int main()
{
	srand(time(NULL));
	int random, a[N] = {0};
	int i, j, x = 0, y = 0;
	while (1)
	{
		x = 0;
		if (y == N)
			break;

		random = (rand() % (max - min+1)) + min;
		for (i = 0; i < y; i++)
		{
			if (a[i] == random)
				x = 1;
		}
		if (x != 1)
		{
			a[y] = random;
			printf("第%d个数是: %d\n", y + 1, a[y]);
			y++;
		}
	}
	return 0;
}