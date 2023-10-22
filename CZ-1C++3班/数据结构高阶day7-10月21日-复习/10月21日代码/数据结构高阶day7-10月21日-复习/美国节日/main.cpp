#include<stdio.h>

int zeller(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{ 
		year--;
		month += 12;
	}
	int c = year / 100;
	int y = year - c * 100;
	int week = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
	while (week < 0)
		week += 7;
	week %= 7;

	return week;
}

int getMonday(int week, int yday)
{
	int weekday = (yday - 1 + week) % 7;
	if (weekday == 0)
	{
		return 2;
	}
	else if (weekday == 1)
	{
		return 1;
	}
	else
	{
		return 9 - weekday;
	}
}

int isLeap(int year)
{
	return year % 400 == 0 ||
		   year % 4 == 0 && year % 100 != 0;
}

int getyday(int year, int month, int day)
{
	int i;
	int sum = 0;
	for (i = 1; i < month; i++)
	{
		switch (i)
		{
		case 2:
			sum += 28 + isLeap(year);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			sum += 30;
			break;
		default:
			sum += 31;
		}
	}
	return sum + day;
}

int main()
{
	int year;
	scanf("%d", &year);
	int ydays[4] = { 0 };
	ydays[0] = 1;
	ydays[1] = getyday(1999, 2, 1);
	ydays[2] = getyday(1999, 5, 1);
	ydays[3] = getyday(1999, 9, 1);
	int weeknum, weekmon;
	printf("%d-01-01\n", year);
	weeknum = zeller(year, 1, 1);
	weekmon = getMonday(weeknum, ydays[0]);
	printf("%d-01-%02d\n", year, weekmon + 14);
	weekmon = getMonday(weeknum, ydays[1]);
	printf("%d-02-%02d\n", year, weekmon + 14);
	weekmon = getMonday(weeknum, ydays[2]);
	if (weekmon + 28 > 31)
	{
		printf("%d-05-%02d\n", year, weekmon + 21);
	}
	else
	{
		printf("%d-05-%02d\n", year, weekmon + 28);
	}
	printf("%d-07-04\n", year);
	weekmon = getMonday(weeknum, ydays[3]);
	printf("%d-09-%02d\n", year, weekmon);

	return 0;
}