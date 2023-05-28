#include <stdio.h>

union Test
{
	int a;
	struct
	{
		char a;
		char b : 1;
		char c : 2;
		char d : 3;
	}b;
	char c[4];
};

int main()
{
	union Test t = { 0 };
	t.b.a = 1;
	t.b.b = 2;
	t.b.c = 3;
	t.b.d = 4;
	printf("%02x %02x %02x %02x\n",
		t.c[0], t.c[1], t.c[2], t.c[3]);

	return 0;
}