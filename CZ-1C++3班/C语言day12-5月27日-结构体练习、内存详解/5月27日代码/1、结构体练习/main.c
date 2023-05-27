#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int no;
	char name[12];
	int s3;
	int alls;
}STU;

int cmpstu(STU a, STU b)
{
	if (a.alls < b.alls)
	{
		return 1;
	}
	else if (a.alls == b.alls)
	{
		if (a.s3 < b.s3)
		{
			return 1;
		}
		else if (a.s3 == b.s3)
		{
			if (a.no > b.no)
			{
				return 1;
			}
		}
	}
	return 0;
}

void bubbleSort(STU *arr, int n)
{
	STU tmp;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			/*if (arr[j].alls < arr[j + 1].alls ||
				arr[j].alls == arr[j + 1].alls && arr[j].s3 < arr[j + 1].s3 ||
				arr[j].alls == arr[j + 1].alls && arr[j].s3 == arr[j + 1].s3 && arr[j].no > arr[j + 1].no)*/
			if(cmpstu(arr[j], arr[j + 1]))
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
	int n;
	scanf("%d", &n);
	STU* stumsg = (STU*)malloc(n * sizeof(STU));
	if (stumsg == NULL)
	{
		printf("malloc error\n");
		return -1;
	}

	int i;
	int s1, s2;
	for (i = 0; i < n; i++)
	{
		stumsg[i].no = i;
		scanf("%s%d%d%d", stumsg[i].name, &s1, &s2, &stumsg[i].s3);
		stumsg[i].alls = s1 + s2 + stumsg[i].s3;
	}

	bubbleSort(stumsg, n);

	for (i = 0; i < n * 6 / 10; i++)
	{
		printf("%d %s %d %d\n",
			stumsg[i].no,
			stumsg[i].name,
			stumsg[i].s3,
			stumsg[i].alls);
	}

	free(stumsg);
	return 0;
}
