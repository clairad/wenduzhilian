#include <stdio.h>
#include <string.h>

void insectionSort(char arr[][102], int n)
{
	int i, j;
	char tmp[102];
	for (i = 1; i < n; i++)
	{
		strcpy(tmp, arr[i]);
		for (j = i; j > 0 && strcmp(tmp, arr[j - 1]) < 0; j--)
		{
			strcpy(arr[j], arr[j - 1]);
		}
		strcpy(arr[j], tmp);
	}
}

int getres(char arr[][102], char res[][102], char *tmp, int n)
{
	int len = strlen(tmp);
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		if (strncmp(arr[i], tmp, len) == 0)
		{
			strcpy(res[j], arr[i]);
			j++;
		}
	}
	return j;
}

char arr[100001][102];
char res[100001][102];
int main()
{
	int n;
	char tmp[102];
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}
	scanf("%s", tmp);

	int len = getres(arr, res, tmp, n);
	insectionSort(res, len);

	for (i = 0; i < len; i++)
	{
		puts(res[i]);
	}
	return 0;
}
