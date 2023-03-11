#include <stdio.h>

int main()
{
	char ch = getchar();

	//printf("%d", ch - 48); //魔鬼数字
	//printf("%d", ch - '0'); //转数字的标准写法
	printf("%c\n", ch - ('a' - 'A')); //小写转大写

	printf("%G", 25412000000000000000000.0);

	return 0;
}
