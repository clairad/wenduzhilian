#include <stdio.h>

int main()
{
	int week, days;
	scanf("%d%d", &week, &days);

	printf("�� һ �� �� �� �� ��\n");
	int i, j;
	int tmp;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			tmp = i * 7 + j + 1 - week;
			if(tmp >= 1 && tmp <= days)
			{
				printf("%2d ", tmp);
			}
			else
			{
				printf("   ");
			}
		}
		putchar('\n');
	}

	return 0;
}
