#include <stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	//1����һ���������߼�
	//2�������������߼�����������
	//3���߼����û����ӣ��߼���������������
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
