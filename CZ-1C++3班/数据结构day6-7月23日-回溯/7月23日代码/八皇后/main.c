#include <stdio.h>

int chessBoard[8];
int line[8];
int cross1[15];
int cross2[15];
int count;

void printRes()
{
	int i, j;
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (chessBoard[i] == j)
			{
				printf("¡ñ");
			}
			else
			{
				printf("¡ð");
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

int eightQueen(int x)
{
	if (x == 8)
	{
		count++;
		printf("%d:\n", count); 
		printRes();
		return count;
	}

	int y;
	for (y = 0; y < 8; y++)
	{
		if (cross1[x + y] || cross2[x - y + 7] || line[y])
		{
			continue;
		}
		chessBoard[x] = y;
		cross1[x + y] = cross2[x - y + 7] = line[y] = 1;
		eightQueen(x + 1);
		cross1[x + y] = cross2[x - y + 7] = line[y] = 0;
	}
	return count;
}

int main()
{
	printf("%d", eightQueen(0));
	return 0;
}
