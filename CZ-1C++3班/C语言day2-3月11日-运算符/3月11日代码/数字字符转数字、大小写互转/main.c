#include <stdio.h>

int main()
{
	char ch = getchar();

	//printf("%d", ch - 48); //ħ������
	//printf("%d", ch - '0'); //ת���ֵı�׼д��
	printf("%c\n", ch - ('a' - 'A')); //Сдת��д

	printf("%G", 25412000000000000000000.0);

	return 0;
}
