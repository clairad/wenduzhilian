#include <stdio.h>

int a[100][100] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void clearStars(int x, int y)
{
	if (a[x][y] == 0)
	{
		return;
	}
	a[x][y] = 0;

	clearStars(x - 1, y - 1);
	clearStars(x - 1, y + 1);
	clearStars(x + 1, y - 1);
	clearStars(x + 1, y + 1);
	clearStars(x + 1, y);
	clearStars(x - 1, y);
	clearStars(x, y + 1);
	clearStars(x, y - 1);
}

void printSky(int m, int n)
{
	int i, j;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	int m = 10, n = 11;

	int i, j;
	int count = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j])
			{
				count++;
				clearStars(i, j);
				//printSky(m, n);
				//putchar('\n');
			}
		}
	}
	printf("%d", count);
	return 0;
}
