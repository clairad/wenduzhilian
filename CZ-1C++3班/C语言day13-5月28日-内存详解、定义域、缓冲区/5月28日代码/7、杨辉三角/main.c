#include <stdio.h>

void printArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%3d ", arr[i]);
	}
	putchar('\n');
}

int main()
{
	int a[30] = { 1 };
	int n;
	scanf("%d", &n);
	printf("  1\n");

	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			a[j] += a[j - 1];
		}
		printArray(a, i + 1);
	}
	return 0;
}
