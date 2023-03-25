#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int tmp = 1;
	int sum = 0;
	for (i = 1; i <= n; i++) //µü´ú·¨
	{
		tmp *= i;
		sum += tmp;
	}

	printf("%d", sum);
	return 0;
}
