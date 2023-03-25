#include <stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	//1、找一定成立的逻辑
	//2、找有条件的逻辑和它的条件
	//3、逻辑间用或连接，逻辑和条件用与连接
	if (year < 0)
	{
		year++;
	}

	if (year % 400 == 0 ||
		year % 4 == 0 && year % 100 != 0)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
