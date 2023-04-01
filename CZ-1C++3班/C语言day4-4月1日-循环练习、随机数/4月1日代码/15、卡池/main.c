#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000

int main()
{
	srand(time(NULL));
	rand();
	int src[SIZE];

	int i;
	for (i = 0; i < SIZE; i++)
	{
		src[i] = i + 1;
	}

	int dst[SIZE];
	int r;

	for (i = 0; i < SIZE; i++)
	{
		r = rand() % SIZE;
		while (src[r] < 0)
		{
			r++;
			r %= SIZE; //让数组转起来
		}
		dst[i] = src[r];
		src[r] = -1;
	}
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", dst[i]);
	}

	return 0;
}
