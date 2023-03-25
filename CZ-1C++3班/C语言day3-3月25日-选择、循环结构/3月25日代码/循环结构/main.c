#include <stdio.h>

int main()
{
	int i = 1;
	int n;
	scanf("%d", &n);

	int sum = 0;
	/*while (i <= n)
	{
		sum += i;
		i++;
	}*/

	for (i = 1; i <= n; i++) //±éÀú
	{
		sum += i;
	}

	printf("%d", sum);
	return 0;
}
