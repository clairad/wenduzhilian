#include <stdio.h>

int main()
{
	char ch = getchar();

	if (ch >= '0' && ch <= '9')
	{
		printf("�����ַ�");
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		printf("��д��ĸ");
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("Сд��ĸ");
	}
	else if (ch > ' ' && ch < 127)
	{
		printf("�����ɼ��ַ�");
	}
	else
	{
		printf("���ɼ��ַ�");
	}
	return 0;
}
