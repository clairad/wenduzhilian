#include <stdio.h>

int main()
{
	int arr[100] = {0};
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int j = 1;
	for (i = 1; i < n; i++)
	{
		if (arr[i - 1] != arr[i])
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
