#include <stdio.h>
#include <stdlib.h>

void check(int **pdata, int *pcapacity, int i)
{
	if (i == *pcapacity)
	{
		*pcapacity *= 2;
		*pdata = (int*)realloc(*pdata, *pcapacity * sizeof(int));
	}
}

int main()
{
	int capacity = 10;
	int size = 0;
	int* data = (int*)malloc(capacity * sizeof(int));

	int i;
	for (i = 0; ; i++)
	{
		check(&data, &capacity, i);
		size++;
		scanf("%d", data + i);
		if (data[i] == -1)
		{
			break;
		}
	}
	
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}

	free(data);
	return 0;
}
