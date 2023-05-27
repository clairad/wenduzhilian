#include <stdio.h>

int main(int args, const char* argv[])
{
	int i;
	for (i = 0; i < args; i++)
	{
		puts(argv[i]);
	}
	return 0;
}
