#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	scanf("%lld", &n);

	long long i = 2;
	long long tmp = n;
	while (i <= sqrt(n))
	{
		if (n % i == 0)
		{
			printf("%lld*", i);
			n /= i;
		}
		else
		{
			i++;
		}
	}
	if (tmp == n)
	{
		printf("is prime");
	}
	else
	{
		printf("%lld", n);
	}
	
	return 0;
}
