#include <stdio.h>

int countmine(int minemap[][11], int x, int y)
{
	int i, j, count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (minemap[i][j] == -1)
			{
				count++;
			}
		}
	}
	return count;
}

void setnum(int minemap[][11], int x, int y)
{
	int i, j;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (minemap[i][j] == -1)
			{
				continue;
			}
			minemap[i][j] = countmine(minemap, i, j);
		}
	}
}

int main()
{
	int minemap[11][11] ={
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 ,-1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 ,-1 ,-1 , 0 , 0 , 0 , 0 ,-1 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 ,-1 , 0 ,-1 , 0 ,-1 , 0 , 0 ,-1 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,-1 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 ,-1 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,-1 , 0 },
		{ 0 ,-1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } };


	setnum(minemap, 9, 9);
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (minemap[i][j] == -1)
			{
				printf("ก่");
			}
			else
			{
				printf("%2d", minemap[i][j]);
			}
		}
		putchar('\n');
	}
	return 0;
}
