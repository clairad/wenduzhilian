#include <stdio.h>
#include <string.h>

int getSum(int n, int m)
{
	if (n == 0)
	{
		return 0;
	}
	return getSum(n / m, m) + n % m;
}

void turn(int n, int m)
{
	if(n > 0)
	{ 
		turn(n / m, m);
		putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
	}
}

void reverseString(char* str)
{
	if (*str)
	{
		int len = strlen(str);
		char tmp = str[len - 1];
		str[len - 1] = '\0';
		reverseString(str + 1);
		str[len - 1] = str[0];
		str[0] = tmp;
	}
}

void printSum(int *arr, int n, int start, int sum, int m)
{
	if (m == 0)
	{
		printf("%d ", sum);
		return;
	}

	int i;
	for (i = start; i < n; i++)
	{
		printSum(arr, n, i + 1, sum + arr[i], m - 1);
	}
}

int count = 0;
int getNum(int n)
{
	count++;
	if (n == 1)
	{
		return count;
	}

	int i;
	for (i = 1; i <= n / 2; i++)
	{
		getNum(i);
	}
	return count;
}

int divideNumss(int n, int k, int start, int remain)
{
	if (k == 1)
	{
		if (remain >= start)
		{
			count++;
		}
		return count;
	}

	int i;
	for (i = start; i <= remain; i++)
	{
		divideNum(n, k - 1, i, remain - i);
	}
	return count;
}

int divideNum(int n, int k, int start)
{
	if (k == 1)
	{
		//printf("%d\n", n);
		count++;
		return count;
	}

	int i;
	for (i = start; i <= n / k; i++)
	{
		//printf("%d ", i);
		divideNum(n - i, k - 1, i);
	}
	return count;
}

int main()
{
	//printf("%d", getSum(1024, 2));
	//turn(84965, 16);

	//char str[32] = "wenduzhilian";
	//reverseString(str);
	//puts(str);

	//int arr[8] = { 1,2,3,4,5,6,7,8 };
	//printSum(arr, 8, 0, 0, 4);

	printf("%d", divideNum(12, 3, 1));
	return 0;
}
