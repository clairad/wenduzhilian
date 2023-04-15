#include <stdio.h>

void reverse(int arr[], int s, int e)
{
	int i, j;
	int tmp;
	for (i = s, j = e - 1; i < j; i++, j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[128] = { 0 };
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	reverse(arr, 0, n);
	reverse(arr, 0, m);
	reverse(arr, m, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


int hw3()
{
	int n;
	scanf("%d", &n);
	int arr[100] = {0};

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int maxnum = arr[0];
	int max = 1;
	int tmp = 1;
	for (i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			tmp++;
		}
		else
		{
			if (tmp > max)
			{
				max = tmp;
				maxnum = arr[i - 1];
			}
			tmp = 1;
		}
	}

	if (tmp > max)
	{
		max = tmp;
		maxnum = arr[i - 1];
	}

	printf("%d", maxnum);
	return 0;
}

int hw2()
{
	int murder[4] = { 0 };

	int i;
	for (i = 0; i < 4; i++)
	{
		murder[i] = 1;
		if (!murder[0] + murder[2] + murder[3] + !murder[3] == 3)
		{
			printf("Ð×ÊÖÊÇ%c\n", 'A' + i);
		}
		murder[i] = 0;
	}
	return 0;
}

int hw1()
{
	int  m, n;

	scanf("%d%d", &m, &n);

	int i, sum = 0;
	int s;
	for(s = 0; s <= 30; s++)
	{ 
		for (i = n; i; i /= m)
		{
			sum = sum * m + i % m;
		}
		if (sum == n)
		{
			printf("STEP=%d", s);
			return 0;
		}
		n += sum;
		sum = 0;
	}
	printf("Impossible");
	return 0;
}
