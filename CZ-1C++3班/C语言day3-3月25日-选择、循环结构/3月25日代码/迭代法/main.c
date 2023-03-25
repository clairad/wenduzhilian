#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);

	int tmp = 0, sum = 0;
	int i;
	for (i = 0; i < m; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}

	printf("%d", sum);
	return 0;
}
