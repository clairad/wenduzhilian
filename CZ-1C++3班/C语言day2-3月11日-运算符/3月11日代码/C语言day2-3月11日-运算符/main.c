#include <stdio.h>

int main()
{
	int a = -9;
	long long b = -9;
	float f = 3.14;
	unsigned int i = 6;
	if (a + i < 0)
	{
		printf("向有符号看齐\n");
	}
	else
	{
		printf("向无符号看齐\n");
	}

	printf("%lld\n", sizeof(a + b));
	printf("%lld\n", sizeof(f + b));
	return 0;
}
//整型向浮点型看齐
//短类型向长类型看齐
//有符号向无符号看齐