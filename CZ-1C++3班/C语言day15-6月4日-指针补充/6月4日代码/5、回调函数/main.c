#include <stdio.h>

void bubbleSort(int *arr, int n, int (*cmp)(int, int))
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (cmp(arr[j], arr[j + 1]))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


int cmpint_desc(int a, int b)
{
	return a < b;
}

int cmpint_asc(int a, int b)
{
	return a > b;
}

int countnum(int arr[], int n, int (*cif)(int))
{
	int count = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (cif(arr[i]))
		{
			count++;
		}
	}
	return count;
}

int countTrue(int n)
{
	return n <= 8 && n >= 5;
}

int main()
{
	int arr[10] = { 8,7,2,4,1,5,0,9,6,3 };

	bubbleSort(arr, 10, cmpint_asc);
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
