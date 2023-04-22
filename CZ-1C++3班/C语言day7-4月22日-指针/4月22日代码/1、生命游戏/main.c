#include <stdio.h>
#include <windows.h>

int countmine(int minemap[][30], int x, int y)
{
	int i, j, count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			count += minemap[i][j];
		}
	}
	return count - minemap[x][y];
}

void nextstep(int minemap[][30], int x, int y)
{
	int tmpmap[30][30] = { 0 };
	int i, j;
	int tmp;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			tmp = countmine(minemap, i, j);
			if (tmp == 2)
			{
				tmpmap[i][j] = minemap[i][j];
			}
			else if (tmp == 3)
			{
				tmpmap[i][j] = 1;
			}
			else
			{
				tmpmap[i][j] = 0;
			}
		}
	}

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			minemap[i][j] = tmpmap[i][j];
		}
	}
}

int main()
{
	int lifegame[30][30] = {
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 },
	{ 0 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } };

	int i, j;
	while(1)
	{ 
		for (i = 1; i < 30; i++)
		{
			for (j = 1; j < 30; j++)
			{
				if (lifegame[i][j])
				{
					printf("¡ö");
				}
				else
				{
					printf("  ");
				}
			}
			putchar('\n');
		}

		nextstep(lifegame, 29, 29);
		Sleep(100);
		system("cls");
	}
	return 0;
}
