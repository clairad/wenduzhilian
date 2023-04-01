#include <stdio.h>

int main()
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	int leapflag = 0;
	if (y % 400 == 0 ||
		y % 4 == 0 && y % 100 != 0)
	{
		leapflag = 1;
	}

	int i;
	int res = 0;
	for (i = 1; i < m; i++)
	{
		switch (i)
		{
		case 2:
			res += 28 + leapflag;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			res += 30;
			break;
		default:
			res += 31;
		}
	}

	printf("%d", res + d);
	return 0;
}

int hw3()
{
	long long i;
	for (i = 1; i < 1e10; i <<= 1)
	{
		printf("%lld\n", i);
	}

	return 0;
}

int hw2()
{
	int i;
	double sum = 0;
	int tmp = 1;

	for (i = 1; i <= 100; i++)
	{
		sum += 1.0 / i * tmp;
		tmp *= -1;
	}

	printf("%lf", sum);
	return 0;
}

int hw1()
{
	int n;
	scanf("%d", &n);

	int i;
	int tmp = 1, sum = 0;
	for (i = 0; i <= n; i++)
	{
		sum += tmp;
		tmp *= 3;
	}
	printf("%d", sum);
	return 0;
}
