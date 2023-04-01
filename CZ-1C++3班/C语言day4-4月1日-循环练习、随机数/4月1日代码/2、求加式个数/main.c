#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= i; j++)
		{
			putchar('*');
			putchar(' ');
		}
		putchar('\n');
	}

	for (i = n; i > 0; i--)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= i; j++)
		{
			putchar('*');
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

