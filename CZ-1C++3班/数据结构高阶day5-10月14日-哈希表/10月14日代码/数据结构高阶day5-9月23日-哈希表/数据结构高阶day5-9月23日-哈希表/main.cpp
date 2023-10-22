#include <iostream>
using namespace std;

bool haveLine(char chessboard[][24], int x, int y, char ch)
{
	int i;
	for (i = y - 2; i <= y + 2; i++)
	{
		if (chessboard[x][i] != ch)
		{
			break;
		}
	}

	if (i > y + 2)
	{
		return true;
	}

	for (i = x - 2; i <= x + 2; i++)
	{
		if (chessboard[i][y] != ch)
		{
			break;
		}
	}

	if (i > x + 2)
	{
		return true;
	}

	int j;
	for (i = x - 2, j = y - 2; i <= x + 2; i++, j++)
	{
		if (chessboard[i][j] != ch)
		{
			break;
		}
	}

	if (i > x + 2)
	{
		return true;
	}

	for (i = x - 2, j = y + 2; i <= x + 2; i++, j--)
	{
		if (chessboard[i][j] != ch)
		{
			break;
		}
	}

	if (i > x + 2)
	{
		return true;
	}

	return false;
}

int main()
{
	char chessboard[24][24] = {0};

	int i;
	for (i = 2; i <= 21; i++)
	{
		cin >> chessboard[i] + 2;
	}

	int j;
	for (i = 2; i < 22; i++)
	{
		for (j = 2; j < 22; j++)
		{
			if ((chessboard[i][j] == '+' || chessboard[i][j] == '*') &&
				haveLine(chessboard, i, j, chessboard[i][j]))
			{
				//cout << i << ',' << j << endl;
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}