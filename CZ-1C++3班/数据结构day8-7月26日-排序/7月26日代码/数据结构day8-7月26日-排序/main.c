#include <stdio.h>
#include "sort.h"

int main()
{
	int arr[10] = { 9,4,7,10,2,1,8,5,6,3 };
	mergeSort(arr, 10);

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
