#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	int sum = 0;
	int i;
	for (i = n; i; i /= 10)
	{
		sum = sum * 10 + i % 10;
	}

	if (sum == n)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
