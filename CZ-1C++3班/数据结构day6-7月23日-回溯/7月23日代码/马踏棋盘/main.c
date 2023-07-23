#include <stdio.h>
#include <windows.h>

int count = 0;
void knightOnTheChessBoard(int x, int y, int a[][12])
{
	if (a[x][y])
	{
		return;
	}
	count++;
	//printf("%d\n", count);
	a[x][y] = count;

	system("cls");
	int i, j;
	for (i = 2; i < 10; i++)
	{
		for (j = 2; j < 10; j++)
		{
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	Sleep(200);

	knightOnTheChessBoard(x - 1, y - 2, a);
	knightOnTheChessBoard(x + 1, y - 2, a);
	knightOnTheChessBoard(x - 1, y + 2, a);
	knightOnTheChessBoard(x + 1, y + 2, a);
	knightOnTheChessBoard(x - 2, y - 1, a);
	knightOnTheChessBoard(x + 2, y - 1, a);
	knightOnTheChessBoard(x - 2, y + 1, a);
	knightOnTheChessBoard(x + 2, y + 1, a);
	a[x][y] = 0;
	count--;
}


int main()
{
	int a[12][12] = {
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
	};
	knightOnTheChessBoard(2, 2, a);
	int i, j;
	for (i = 2; i < 10; i++)
	{
		for (j = 2; j < 10; j++)
		{
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return 0;
}
