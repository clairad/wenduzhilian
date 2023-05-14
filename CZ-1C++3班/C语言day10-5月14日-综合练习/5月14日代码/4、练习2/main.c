#include <stdio.h>

int ldate(int y, int m, int d)
{
	int leapFlag = 0;
	if (y % 400 == 0 ||
		y % 4 == 0 && y % 100 != 0)
	{
		leapFlag = 1;
	}

	if (d > 31 || d < 1 || m > 12 || m < 1 ||
		d > 30 && (m == 4 || m == 6 || m == 9 || m == 11) ||
		d > 28 + leapFlag && m == 2)
	{
		return 0;
	}
	return 1;
}


int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	int i, j, sum = 0, count = 0;
	for (i = a; i <= b; i++)
	{
		if (ldate(i / 10000, i / 100 % 100, i % 100))
		{
			for (j = i; j; j /= 10)
			{
				sum = sum * 10 + j % 10;
			}
			if (sum == i)
			{
				count++;
			}
			sum = 0;
		}
	}

	printf("%d\n", count);
	return 0;
}
