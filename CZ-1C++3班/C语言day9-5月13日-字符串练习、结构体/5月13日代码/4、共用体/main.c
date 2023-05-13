#include <stdio.h>

union Test
{
	int a;
	float b;
	char c[4];
};

//IDE
int main()
{
	//printf("%d", sizeof(union Test));
	union Test t;
	t.a = 0x43900000;
	printf("%f\n", t.b);
	printf("%x %x %x %x\n", t.c[0], t.c[1], t.c[2], t.c[3]);

	return 0;
}
