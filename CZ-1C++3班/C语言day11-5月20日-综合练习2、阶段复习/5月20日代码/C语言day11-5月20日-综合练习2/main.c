#include <stdio.h>
#include <string.h>
#include <math.h>

int getSum(int n, int m)
{
	int i;
	int tmp = 1, sum = 0;
	for (i = m; i; i /= 2)
	{
		sum += tmp * (i % 2);
		tmp *= n;
	}
	return sum;
}

long long reverseNum(long long n)
{
	long long i;
	long long sum = 0;
	for (i = n; i; i /= 10)
	{
		sum = sum * 10 + i % 10;
	}
	return sum;
}

int factory(const char *str)
{
	long long a, b;
	if (strchr(str, '.'))
	{
		sscanf(str, "%lld.%lld", &a, &b);
		printf("%lld.%lld",
			reverseNum(a),
			reverseNum(b));
	}
	else if (strchr(str, '/'))
	{
		sscanf(str, "%lld/%lld", &a, &b);
		printf("%lld/%lld",
			reverseNum(a),
			reverseNum(b));
	}
	else if (strchr(str, '%'))
	{
		sscanf(str, "%lld", &a);
		printf("%lld%%", reverseNum(a));
	}
	else
	{
		sscanf(str, "%lld", &a);
		printf("%lld", reverseNum(a));
	}
}

int distance(int w, int m, int n)
{
	m--, n--;
	int x1 = m / w;
	int y1 = m % w;
	if (x1 % 2)
	{
		y1 = w - 1 - y1;
	}
	int x2 = n / w;
	int y2 = n % w;
	if (x2 % 2)
	{
		y2 = w - 1 - y2;
	}
	return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
#if 0 //数列
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", getSum(n, m));
	return 0;
#elif 0 //数字翻转
	long long a, b;
	char str[32];
	scanf("%31s", str);
	factory(str);
#elif 1 //移动距离
	int w, m, n;
	scanf("%d%d%d", &w, &m, &n);
	printf("%d", distance(w, m, n));
#endif
}
