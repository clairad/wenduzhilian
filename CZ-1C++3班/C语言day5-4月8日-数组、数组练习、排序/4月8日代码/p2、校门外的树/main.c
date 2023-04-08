#include <stdio.h>

int main()
{
	int start[100] = {0};
	int end[100] = {0};

	int l, m;
	scanf("%d%d", &l, &m);

	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &start[i], &end[i]);
	}

	int j, tmp;
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < m - 1 - i; j++)
		{
			if (start[j] > start[j + 1])
			{
				tmp = start[j];
				start[j] = start[j + 1];
				start[j + 1] = tmp;

				tmp = end[j];
				end[j] = end[j + 1];
				end[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < m - 1; i++)
	{
		if (end[i] > start[i + 1])
		{
			start[i + 1] = end[i] + 1;
			if (end[i] > end[i + 1])
			{
				end[i + 1] = end[i];
			}
		}
	}

	int sum = 0;
	for (i = 0; i < m; i++)
	{
		sum += end[i] - start[i] + 1;
		//printf("%d %d\n", start[i], end[i]);
	}

	printf("%d", l - sum + 1);
	return 0;
}
