#include <stdio.h>
#include <math.h>
//输入两个数，求最大公约数

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);

	int a, b, _mod;
	a = m, b = n;

	_mod = a % b;
	while (_mod)
	{
		a = b;
		b = _mod;
		_mod = a % b;
	}

	printf("%d %d", b, m * n / b);

	return 0;
}

int way1()
{
	int m, n;
	scanf("%d%d", &m, &n);

	int tmp = m < n ? m : n;
	int i;
	int max = 1;
	for (i = 2; i <= tmp; i++)
	{
		if (m % i == 0 && n % i == 0)
		{
			max = i;
		}
	}
	
	printf("%d", max);
	return 0;
}
