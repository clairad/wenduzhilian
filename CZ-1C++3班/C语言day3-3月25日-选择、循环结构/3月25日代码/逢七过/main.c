#include <stdio.h>

int main()
{
	int i;
	for (i = 0; i <= 100; i++)
	{
		if (i % 10 == 7 ||
			i / 10 == 7 ||
			i % 7 == 0)
		{
			continue;
		}
		printf("%d ", i);
	}
	return 0;
}

int main1()
{
	int tmp;
	while (1)
	{
		scanf("%d", &tmp);
		if (tmp % 7 == 0)
		{
			break;
		}
	}
	return 0;
}
