#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	rand();

	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%.3lf ", ((rand() << 15) + rand()) % 100000 / 1000.0);
	}
	
	return 0;
}


