#include <stdio.h>

int main()
{
	int a = 321;
	char ch = a;
	//1 0100 0001
	//  0100 0001
	//短类型给长类型会截断高位
	printf("%d\n", ch);

	unsigned char ch2 = -1;
	int a2 = ch2;
	//字节提升：补符号位，无符号就补0

	printf("%d", a2);
	return 0;
}
