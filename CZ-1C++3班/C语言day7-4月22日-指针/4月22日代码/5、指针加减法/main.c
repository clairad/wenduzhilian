#include <stdio.h>

void func(char(*st)[10])
{
	char(*a[10])[10];
}

int main()
{
	char a[5] = {1,2,3,4,5};
	char* p = a;

	char(*pa)[5] = &a;

	printf("%p %p\n", p, p + 1);
	printf("%d %d\n", *p, *(p + 1));
	printf("%d %d\n", p[0], p[1]);

	char st[10][10] = { {1,2,3},{4,5,6},{7,8,9} };
	char(*pst)[10] = st; //Êý×éÖ¸Õë
	char* pc = (char *)st;

	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%2d", pc[i]);
	}
	return 0;
}
