#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	n = (n & 0x55555555) + (n >> 1 & 0x55555555);
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);

	printf("%d", n);
	return 0;
}

int way2()
{
	int n;
	scanf("%d", &n);

	int count = 0;
	while (n)
	{
		n &= n - 1;
		count++;
	}

	printf("%d", count);
	return 0;
}

int way1()
{
	int n;
	scanf("%d", &n);

	int i;
	int sum = 0;
	for (i = n; i; i /= 2)
	{
		sum += i % 2;
	}

	printf("%d", sum);
	return 0;
}
