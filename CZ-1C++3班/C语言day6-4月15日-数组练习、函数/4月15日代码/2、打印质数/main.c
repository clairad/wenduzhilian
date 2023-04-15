#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	int i;
	int tmp = sqrt(n);
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

//函数提高了代码的可读性
int main()
{
	int n;
	scanf("%d", &n);
	int i;

	for (i = 2; i < n; i++)
	{
		if (is_prime(i))
		{
			printf("%d ", i);
		}
	}
	
	return 0;
}
