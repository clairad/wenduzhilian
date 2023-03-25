#include <stdio.h>

int main()
{
	int y, m, d;
	int leapflag = 0;

	scanf("%d%d%d", &y, &m, &d);

	if (y % 400 == 0 ||
		y % 4 == 0 && y % 100 != 0)
	{
		leapflag = 1;
	}

	if (m > 12 || m < 1 || d > 31 || d < 1 ||
		d > 30 && (m == 4 || m == 6 || m == 9 || m == 11) ||
		d > 28 + leapflag && m == 2)
	{
		printf("不合法");
	}
	else
	{
		printf("合法");
	}

	return 0;
}
