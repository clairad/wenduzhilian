#include <stdio.h>

int main()
{
	double tmp = 0, sum = 0;
	int i;
	for (i = 1; i <= 100; i++)
	{
		tmp = 1.0 / i;
		sum += tmp;
	}

	printf("%lf", sum);
	return 0;
}
