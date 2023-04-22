#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pch1 = (int*)malloc(100 * sizeof(int));
	if (pch1 == NULL)
	{
		return 0;
	}

	int* pch2 = (int*)calloc(100, sizeof(int));
	if (pch2 == NULL)
	{
		return 0;
	}
	pch1 = (int*)realloc(pch1, 200 * sizeof(int));
	if (pch1 == NULL)
	{
		return 0;
	}


	free(pch2);
	pch1 = NULL;
	return 0;
}
