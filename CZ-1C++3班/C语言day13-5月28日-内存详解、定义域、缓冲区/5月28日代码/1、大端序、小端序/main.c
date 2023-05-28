#include <stdio.h>

union Test{
	int i;
	char a[4];
};

union Bit {
	struct {
		unsigned char ta : 4;
		unsigned char tb : 4;
	}a;
	unsigned char b;
};

int main()
{
	union Test ut;
	ut.i = 1;
	if (ut.a[0] == 1)
	{
		printf("��С����\n");
	}
	else
	{
		printf("�Ǵ����\n");
	}

	int i = 1;
	if (*(char*)&i == 1)
	{
		printf("��С����\n");
	}
	else
	{
		printf("�Ǵ����\n");
	}

	union Bit ub;
	ub.a.ta = 1;
	ub.a.tb = 0;
	printf("%08x", ub.b);
	return 0;
}
