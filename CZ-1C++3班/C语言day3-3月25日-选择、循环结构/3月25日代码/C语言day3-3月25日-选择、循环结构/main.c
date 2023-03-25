#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	int tmp;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	if (b > c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}

	printf("%d", a > b ? a : b);

	return 0;
}

int main2()
{
	int a = 7, b = 5;

	int tmp;
	tmp = a;
	a = b;
	b = tmp;

	/*a = a + b; //  a + b   b
	b = a - b; //  a + b   a
	a = a - b; //  b       a*/

	/*a = a ^ b; // a ^ b  b
	b = a ^ b; // a ^ b  a
	a = a ^ b; // b      a*/

	printf("a = %d, b = %d", a, b);
	return 0;
}

int main3()
{
	int seconds;
	scanf("%d", &seconds);

	printf("%d:%d:%d", 
		seconds / 3600, 
		seconds / 60 % 60, 
		seconds % 60);
	return 0;
}

int main1()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	int bigger = a > b ? a : b;
	int biggest = bigger > c ? bigger : c;
	int smaller = a < b ? a : b;
	int smallest = smaller < c ? smaller : c;
	printf("%d", a ^ b ^ c ^ biggest ^ smallest);
	return 0;
}
