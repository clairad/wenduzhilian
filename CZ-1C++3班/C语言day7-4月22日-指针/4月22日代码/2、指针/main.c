#include <stdio.h>

int main()
{
	int a = 5;
	int* p = &a;

	*p = 8;
	printf("%p %d", p, a);

	/*printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(double*));
	printf("%d\n", sizeof(char*));*/


	return 0;
}


//64位CPU  64位操作系统  64位编译器
