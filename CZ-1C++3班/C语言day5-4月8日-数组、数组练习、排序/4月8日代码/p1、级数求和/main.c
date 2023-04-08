#include <stdio.h>

int main()
{
	double sum = 0;
	int k = 0;
	int i;
	scanf("%d", &k);
	for (i = 1; sum <= k; i++)
	{
		sum += 1.0 / i;
	}

	printf("%d", i - 1);
	return 0;
}
