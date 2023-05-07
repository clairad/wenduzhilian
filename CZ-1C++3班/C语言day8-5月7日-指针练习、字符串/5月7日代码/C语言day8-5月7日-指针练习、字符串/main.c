#include <stdio.h>
#define SWAP(a, b, type) {	type tmp; \
							tmp = a; \
							a = b;   \
							b = tmp;}

void swapArgs(int* pa, int* pb) //ջ֡
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void gcd(int src1, int src2, int* pres1, int* pres2)
{
	int a = src1, b = src2;
	int c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}

	*pres1 = b;
	*pres2 = src1 * src2 / b;
}

void scanPasage()
{
	int capacity = 50;
	char* str = (char*)malloc(capacity * sizeof(char));

	int i;
	int count = 0;
	char tmp;
	for (i = 0; ; i++)
	{
		if (i == capacity)
		{
			capacity *= 2;
			str = (char*)realloc(str, capacity * sizeof(char));
		}
		tmp = getchar();
		str[i] = tmp;
		if (str[i] == '$')
		{
			str[i] = 0;
			break;
		}

		if (str[i] == ' ')
		{
			count++;
		}
	}
	printf("%d", i);
}

int juice(int n)
{
	int tmp = n;
	int sum = n;
	while (tmp >= 3)
	{
		sum += tmp / 3;
		tmp = tmp / 3 + tmp % 3;
	}
	if (tmp == 2)
	{
		sum++;
	}
	return sum;
}

int main()
{
	int a, b;
	//gcd(15, 12, &a, &b);
	//printf("%d %d\n", a, b);

	//scanPasage();
	printf("%d", juice(20));
	return 0;
}
