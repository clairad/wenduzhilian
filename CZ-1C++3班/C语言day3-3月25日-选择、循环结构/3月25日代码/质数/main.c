#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int i;
	int tmp;

	for(n = 2; n <= 1000; n++)
	{ 
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}
		if (i > tmp)
		{
			printf("%d ", n);
		}
	}
	return 0;
}
