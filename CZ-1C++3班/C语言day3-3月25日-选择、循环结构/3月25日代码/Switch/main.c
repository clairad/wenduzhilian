#include <stdio.h>

int main()
{
	int i = 1;

	switch (i)
	{
	case 0: printf("十分满意\n"); break;
	case 1: printf("满意\n"); break;
	case 2:	printf("一般满意\n"); break;
	case 3:	printf("不太满意\n"); break;
	default: printf("输入无效\n");
	}

	return 0;
}
