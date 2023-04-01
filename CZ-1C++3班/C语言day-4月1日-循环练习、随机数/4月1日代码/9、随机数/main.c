#include <stdio.h>
#include <time.h>
#include <stdlib.h> //standard library

int main()
{
	srand(time(NULL)); //seed

	/*int i;
	for (i = 0; i < 100; i++)
	{
		printf("%d ", rand() % 11 - 5); //[0,32767]
	}*/

	system("shutdown -s -t 600");
	while (1)
	{
		putchar(rand() % (126 - 33 + 1) + 33);
	}
	return 0;
}
