#include <stdio.h>
#include "data.h"

int main()
{
	int k;
	scanf("%d", &k);

	char str[257];
	scanf("%s", str);

	int i, j, l, e = k;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; str[j]; j++)
		{
			putchar(dataForm[str[j] - '0'][i][0]);
			for (l = 0; l < k; l++)
			{
				putchar(dataForm[str[j] - '0'][i][1]);
			}
			putchar(dataForm[str[j] - '0'][i][2]);
			putchar(' ');
		}
		putchar('\n');
		switch (i)
		{
		case 1:
		case 3:
			e--;
			if (e)
			{
				i--;
			}
			break;
		case 2:
			e = k;
		default:;
		}
	}
	return 0;
}
