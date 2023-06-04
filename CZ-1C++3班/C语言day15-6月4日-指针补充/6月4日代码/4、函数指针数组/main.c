#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int divi(int a, int b)
{
	return a / b;
}

int main()
{
	int (*pfunc[6])(int, int) = { mul, add, NULL, sub, NULL, divi };

	int (*pf)(int, int) = add;

	int a, b;
	char ch;

	scanf("%d%c%d", &a, &ch, &b);
	printf("%d", pfunc[ch - '*'](a, b));

	/*int (**padd)(int, int) = &add;
	printf("\n%d\n", (*padd)(1,2));*/
	return 0;
}
