#include <stdio.h>

int is_leap(int y)
{
	return  y % 400 == 0 ||
			y % 4 == 0 && y % 100 != 0;
}

int getdays(int y, int m, int d)
{
	int i;
	int res = 0;
	for (i = 1; i < m; i++)
	{
		switch (i)
		{
		case 2:
			res += 28 + is_leap(y);
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

	return res + d;
}

int get_one_num1(int n)
{
	int i;
	int sum = 0;
	for (i = n; i; i /= 2)
	{
		sum += i % 2;
	}

	return sum;
}

int get_one_num2(int n)
{
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count++;
	}

	return count;
}

int get_one_num3(int n)
{
	n = (n & 0x55555555) + (n >> 1 & 0x55555555);
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);

	return n;
}

int main()
{
	printf("%d\n", getdays(2023, 4, 15));
	printf("%d\n", get_one_num3(10));
	return 0;
}
