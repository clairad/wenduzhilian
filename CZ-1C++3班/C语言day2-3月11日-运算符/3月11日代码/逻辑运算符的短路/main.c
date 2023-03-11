#include <stdio.h>

int main()
{
	int i = 0, j = 1;

	j < 0 && i++;
	j > 0 || i++;

	printf("%d", i);
	//j = (2, 3);
	//printf("%d", j);
	return 0;
}
