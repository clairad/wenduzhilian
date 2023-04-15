#include <stdio.h>

int all_exist(int a1, int a2, int a3)
{
	int n = a1 * 1000000 + a2 * 1000 + a3;
	short res = 0;

	int i;
	for (i = n; i; i /= 10)
	{
		res |= 1 << i % 10;
	}

	return res == 0x3fe;
}

//ñîºÏ¶È
int main()
{
	int i;
	for (i = 123; i <= 329; i++)
	{
		if (all_exist(i, i * 2, i * 3))
		{
			printf("%d %d %d\n", i, i * 2, i * 3);
		}
	}
	return 0;
}
