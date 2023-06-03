#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

}

int main()
{
	FILE* pf = fopen("..\\4¡¢Ëæ»úÊýÅÅÐò£¨ÉÏ£©\\data.txt", "r");
	if (pf == NULL)
	{
		printf("open error");
		return 0;
	}
	int n;
	fscanf(pf, "%d", &n);

	int* src = (int*)calloc(n, sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		fscanf(pf, "%d", src + i);
	}

	bubbleSort(src, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}

	fclose(pf);
	free(src);
	return 0;
}
