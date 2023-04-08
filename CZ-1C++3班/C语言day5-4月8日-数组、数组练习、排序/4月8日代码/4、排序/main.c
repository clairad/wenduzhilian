#include <stdio.h>

int main()
{
	int arr[100] = { 0 };
	int n;
	scanf("%d", &n);

	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

#if 0 //—°‘Ò≈≈–Ú
	int tmp;
	int min, minpos;
	for (i = 0; i < n - 1; i++)
	{
		min = arr[i];
		minpos = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minpos = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[minpos];
		arr[minpos] = tmp;
	}

#elif 0 //√∞≈›≈≈–Ú
	int tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
#elif 1 //÷±Ω”≤Â»Î≈≈–Ú
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}

#endif

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
