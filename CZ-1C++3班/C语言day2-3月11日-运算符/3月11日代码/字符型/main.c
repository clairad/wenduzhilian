#include <stdio.h>

int main()
{
	char ch = '\x7e'; //character 

	scanf("%c", &ch);
	printf("%c", ch);

	//ch = getchar();
	//ch = '+';
	//printf("%d %d %d\n", sizeof(3.14), sizeof(0), sizeof('4'));
	//putchar(ch);
	
	//printf("\?"); // 三字母词

	/*
	转义字符：
	1、可见字符 ' " \ ?
	2、不可见字符 ASCII码值0和7~13的字符
	3、八进制和十六进制  \176  \x7e
	*/
	return 0;
}
