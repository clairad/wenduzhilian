#include <stdio.h>

int main()
{
	//int a = 0x426b0000;
	//printf("%.2f", *(float *)&a);

	int a[5] = { 1,2,3,4,5 };
	int* p = a;

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("%d", p > a);
	return 0;
}
