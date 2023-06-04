#include <stdio.h>
#include <stdlib.h>
#include "ManagementSystem.h"

int init(Allmsg *pAllData)
{
	if (load("allData.txt", &pAllData->size, &pAllData->capacity, &pAllData->alldata))
	{
		pAllData->size = 0;
		pAllData->capacity = 10;
		pAllData->alldata = (STU*)calloc(pAllData->capacity, sizeof(STU));
		return 1;
	}
	return 0;
}

int main()
{
	Allmsg allData;

	if (init(&allData))
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			scanf("%d %d %d", &allData.alldata[i].no, &allData.alldata[i].age, &allData.alldata[i].alls);
		}
		allData.size = 10;
		save("allData.txt", allData.size, allData.capacity, allData.alldata);
	}
	else
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			printf("%d %d %d\n", allData.alldata[i].no, allData.alldata[i].age, allData.alldata[i].alls);
		}
	}


	return 0;
}
