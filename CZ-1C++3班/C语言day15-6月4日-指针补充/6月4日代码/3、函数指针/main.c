#include <stdio.h>

int add(int a, int b)
{
	static int count = 1;
	int i;
	printf("%d:%p ", count, &i);
	count++;
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

typedef int (*CACUFUNC)(int, int);
typedef int s32;
typedef int* pint;

int main1()
{
	CACUFUNC pfunc = add;

	//printf("%d", pfunc(5, 6));
	int i;
	for (i = 0; i < 10; i++)
	{
		pfunc(1, 1); //»Øµ÷
		sub(1, 1);
		printf("%p\n", add);
	}
	
	return 0;
}


int g_t = 10;
void test()
{
	if (g_t--)
	{
		int i;
		printf("%d:\n", g_t);
		printf("i = %p\n", &i);
		printf("test = %p\n", test);
		test();
	}
}

int main()
{
	test();
	return 0;
}