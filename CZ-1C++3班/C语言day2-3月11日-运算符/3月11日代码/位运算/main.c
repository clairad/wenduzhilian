#include <stdio.h>

int main()
{
	char ch = getchar();
	
	//putchar(ch | 1 << 5); //给某一位强制写1
	//putchar(ch & ~(1 << 5)); //给某一位强制写0
	putchar(ch ^ 1 << 5); //改变某一位的状态
	
	return 0;
}
