#include <stdio.h>

int main() //ÄæĞò·¨
{
	int arr[100] = {0};

	int n, m;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);

	int j, tmp;
	for (i = 0, j = m - 1; i < j; i++, j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	for (i = m, j = n - 1; i < j; i++, j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

int way1() //Æ´½Ó·¨
{
	int arr[100];
	int tmp[100];

	int n, m;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
#if 0
	m %= n;

	for (i = m; i < n; i++)
	{
		tmp[i - m] = arr[i];
	}

	for (i = 0; i < m; i++)
	{
		tmp[n - m + i] = arr[i];
	}
#else
	for (i = 0; i < n; i++)
	{
		tmp[i] = arr[(i + m) % n];
	}

#endif

	for (i = 0; i < n; i++)
	{
		arr[i] = tmp[i];
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
