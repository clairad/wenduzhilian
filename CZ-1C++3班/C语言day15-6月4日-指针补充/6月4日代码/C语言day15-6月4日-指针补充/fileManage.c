#include "ManagementSystem.h"
#include <stdio.h>
#include <stdlib.h>

void save(const char* fileName, int size, int capacity, STU* data)
{
	FILE* pf = fopen(fileName, "w");
	fwrite(&size, 1, sizeof(int), pf);
	fwrite(&capacity, 1, sizeof(int), pf);
	fwrite(data, size, sizeof(STU), pf);
	fclose(pf);
}

int load(const char* fileName, int * psize, int * pcapacity, STU **pdata)
{
	FILE* pf = fopen(fileName, "r");
	if (pf == NULL)
	{
		printf("open %s error\n", fileName);
		return -1;
	}

	fread(psize, 1, sizeof(int), pf);
	fread(pcapacity, 1, sizeof(int), pf);
	*pdata = (STU*)malloc(*pcapacity * sizeof(STU));
	fread(*pdata, *psize, sizeof(STU), pf);

	fclose(pf);
	return 0;
}