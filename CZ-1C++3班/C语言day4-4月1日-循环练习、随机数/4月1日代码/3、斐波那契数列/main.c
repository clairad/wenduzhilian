#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	if (n <= 2)
	{
		printf("1\n");
	}
	int i;
	int an_1 = 1, an_2 = 1, an = 2;
	for (i = 3; i <= n; i++)
	{
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}

	printf("%d", an);
	return 0;
}
