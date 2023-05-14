#include <stdio.h>
#include <string.h>

void insectionSort(char arr[][11], int n)
{
	int i, j;
	char tmp[11];
	for (i = 1; i < n; i++)
	{
		strcpy(tmp, arr[i]);
		for (j = i; j > 0 && strcmp(tmp, arr[j - 1]) > 0; j--)
		{
			strcpy(arr[j], arr[j - 1]);
		}
		strcpy(arr[j], tmp);
	}
}

int numcmp(char* str1, char* str2)
{
	char tmp1[22];
	char tmp2[22];

	strcpy(tmp1, str1);
	strcat(tmp1, str2);
	strcpy(tmp2, str2);
	strcat(tmp2, str1);
	return strcmp(tmp1, tmp2) > 0;
}

void insectionSortspe(char arr[][11], int n)
{
	int i, j;
	char tmp[11];
	for (i = 1; i < n; i++)
	{
		strcpy(tmp, arr[i]);
		for (j = i; j > 0 && numcmp(tmp, arr[j - 1]); j--)
		{
			strcpy(arr[j], arr[j - 1]);
		}
		strcpy(arr[j], tmp);
	}
}

int main()
{
	char arr[21][11] = { 0 };
	int n;

	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}

	insectionSort(arr, n);
	insectionSortspe(arr, n);
	for (i = 0; i < n; i++)
	{
		printf(arr[i]);
	}
	return 0;
}
