#include <stdio.h>

int main()
{
	//unsigned //加在整型变量前，表示该整型无符号（没有符号位）
	unsigned int uc;
	auto signed short int s;
	uc = -1;
	if (uc < 0) //恒假
	{
		printf("uc小于0");
	}
	//scanf("%u", &uc);
	printf("%x", uc);
	return 0;
}
