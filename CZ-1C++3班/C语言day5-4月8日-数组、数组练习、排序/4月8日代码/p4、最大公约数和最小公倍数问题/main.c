#include <stdio.h>
#include <math.h>

int main()
{
	int x0, y0;

	scanf("%d%d", &x0, &y0);

	int mul = x0 * y0;

	int i;
	int p, q;
	int tmp;
	int count = 0;
	int sy0 = sqrt(mul);
	int flag = 0;
	for (i = x0; i <= sy0; i += x0)
	{
		if (mul % i)
		{
			continue;
		}
		p = i;
		q = mul / p;

		tmp = p % q;
		while (tmp)
		{
			p = q;
			q = tmp;
			tmp = p % q;
		}

		if (q == x0)
		{
			if (i == mul / i)
			{
				flag = 1;
			}
			printf("%d %d\n", i, mul / i);
			count++;
		}
	}

	printf("%d", count * 2 - flag);
	return 0;
}
