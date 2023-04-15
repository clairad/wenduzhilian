#include <stdio.h>
#define X 3
#define Y 5

void func(int arr[], int a[][5])
{

}

int main()
{
	int a[X][Y] = { {1 ,2 ,3 ,4 ,5},
					{6 ,7 ,8 ,9 ,10},
					{11,12,13,14,15}};
	int i, j;
	for (i = 0; i < X; i++) //二维数组遍历
	{
		for (j = 0; j < Y; j++)
		{
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			printf("%2d ", a[j][i]);
		}
		putchar('\n');
	}

	for (i = -X + 1; i < Y; i++)
	{
		j = 0;
		if (i < 0)
		{
			j = -i;
		}
		for (; j < X && i + j < Y; j++) //横纵坐标的差固定
		{
			printf("%2d ", a[j][j + i]);
		}
		putchar('\n');
	}
	
	for (i = 0; i < X + Y - 1; i++)
	{
		j = 0;
		if (i >= Y)
		{
			j = i - Y + 1;
		}
		for (; j < X && i - j >= 0; j++) //横纵坐标的和固定
		{
			printf("%2d ", a[j][i - j]);
		}
		putchar('\n');
	}

	int arr[10];

	func(arr, a);

	//system("pause");
	return 0;
}
