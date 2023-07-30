#include <iostream>
using namespace std;

class Date
{
	int yday;
public:
	int year;
	int month;
	int day;

	Date(int y, int yd)
	{
		year = y;
		yday = yd;
		getMonthDay(year, yday, month, day);
	}

	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
		yday = getYday(y, m, d); //透传
	}

	Date operator+(int i)
	{
		int alldays = yday + i;
		int tmpy = alldays / 365.25;
		int y = tmpy + year;
		alldays -= tmpy * 365 + getLeapYearNum(year, y);
		Date res(y, alldays);
		return res;
	}

	void print()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
private:
	int getYday(int y, int m, int d)
	{
		int alldays = 0;
		int flag = isLeapYear(y);

		int i;
		for (i = 1; i < m; i++)
		{
			switch (i)
			{
			case 4:
			case 6:
			case 9:
			case 11:
				alldays += 30;
				break;
			case 2:
				alldays += 28 + flag;
				break;
			default:
				alldays += 31;
			}
		}
		return alldays + d;
	}

	int getLeapYearNum(int sy, int ey)
	{
		sy--, ey--;
		sy -= sy % 4;
		ey -= ey % 4;
		return (ey - sy) / 4;
	}

	bool isLeapYear(int y)
	{
		return (y % 400 == 0 || y % 4 == 0 && y / 100);
	}

	void getMonthDay(int year, int yday, int& m, int& d)
	{
		m = 1;
		int flag = isLeapYear(year);
		while (1)
		{
			switch (m)
			{
			case 4:
			case 6:
			case 9:
			case 11:
				yday -= 30;
				if (yday <= 0)
				{
					d = yday + 30;
					return;
				}
				break;
			case 2:
				yday -= 28 + flag;
				if (yday <= 0)
				{
					d = yday + 28 + flag;
					return;
				}
				break;
			default:
				yday -= 31;
				if (yday <= 0)
				{
					d = yday + 31;
					return;
				}
			}
			m++;
		}
	}
};

int main()
{
	Date d(2023, 7, 30);

	(d + 1000).print();
		
	return 0;
}
