#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int sum = 0;
	for (i = n; i; i /= 2) //��λ����
	{
		sum += i % 2;
	}

	printf("%d", sum);
	return 0;
}
