#include <stdio.h>
#pragma pack(1)
//����ƿ��

struct Test{
	int i;
	long long l;
	char ch;
};

int main()
{
	printf("%d", sizeof(struct Test));

	return 0;
}
