#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	rand();
	int count[6] = { 0 };

	int i;
	int tmp;
	for (i = 0; i < 1e8; i++)
	{
		tmp = rand() % 6;
		count[tmp]++;
	}

	for (i = 0; i < 6; i++)
	{
		printf("%d出现了%d次\n", i + 1, count[i]);
	}

	return 0;
}
