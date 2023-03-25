#include <stdio.h>

int main()
{
	char ch = getchar();

	if (ch >= '0' && ch <= '9')
	{
		printf("数字字符");
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		printf("大写字母");
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("小写字母");
	}
	else if (ch > ' ' && ch < 127)
	{
		printf("其他可见字符");
	}
	else
	{
		printf("不可见字符");
	}
	return 0;
}
