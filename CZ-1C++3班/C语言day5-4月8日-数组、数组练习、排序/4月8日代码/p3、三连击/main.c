#include <stdio.h>

int main()
{
	int i, tmp;
	short res = 0;
	int j;
	for (i = 123; i <= 329; i++)
	{
		tmp = i * 1000000 + i * 2 * 1000 + i * 3;
		for (j = tmp; j; j /= 10)
		{
			res |= 1 << j % 10;
		}

		if (res == 0x3fe)
		{
			printf("%d %d %d\n", i, i * 2, i * 3);
		}
		res = 0;
	}

	return 0;
}
