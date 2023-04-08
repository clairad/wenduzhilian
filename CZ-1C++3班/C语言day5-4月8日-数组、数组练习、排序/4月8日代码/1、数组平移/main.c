#include <stdio.h>
#define ARRSIZE 5

int main()
{
	int a[ARRSIZE];

	int i;
	for (i = 0; i < ARRSIZE; i++)
	{
		scanf("%d", &a[i]);
	}

	int tmp = a[0];
	for (i = 1; i < ARRSIZE; i++) //Æ½ÒÆ·¨
	{
		a[i - 1] = a[i];
	}
	a[ARRSIZE - 1] = tmp;

	for (i = 0; i < ARRSIZE; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
