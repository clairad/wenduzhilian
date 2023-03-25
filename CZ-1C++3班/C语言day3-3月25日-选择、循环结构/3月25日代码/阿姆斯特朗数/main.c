#include <stdio.h>
#include <math.h>

int main()
{
	int n, i;
	int sum = 0;
	int k = 0;
	int tmp = 1;
	printf("0\n");
	for (n = 1; n < 1E8; n++)
	{
		if (tmp == n)
		{
			tmp *= 10;
			k++;
		}

			for (i = n; i; i /= 10)
			{
				sum += pow(i % 10, k);
			}
			if (sum == n)
			{
				printf("%d\n", sum);
			}
		sum = 0;
	}
	return 0;
}
