#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("char  :%d\n", sizeof(char));
	printf("short :%d\n", sizeof(short));
	printf("int   :%d\n", sizeof(int));
	printf("long  :%d\n", sizeof(long));
	printf("long long:%d\n", sizeof(long long));
	printf("float :%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));

	char ch; //%d %c
	short s; //%hd
	int i; //%d
	long li; //%ld
	long long lli; //%lld
	float f; //%f
	double lf; //%lf

	int test = 0x43EF7000;
	printf("%.2f", *(float *)&test);
	/*int i = 7;
	printf("i  :%d\n", sizeof(i = 3));
	printf("i  :%d\n", i);*/
	return 0;
}
