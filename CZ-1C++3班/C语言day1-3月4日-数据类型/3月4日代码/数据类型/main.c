#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 16;
	int b = 160;

	printf("a = %d%%, b = %d%%\n", a, b);
	//%占位符
	//d类型说明 decimal 十进制的
	//o 八进制 x十六进制

	scanf("%d%d", &a, &b);
	printf("%d %d\n", a, b);
	return 0;
}
