#include <stdio.h>

int main()
{
	char ch = '\x7e'; //character 

	scanf("%c", &ch);
	printf("%c", ch);

	//ch = getchar();
	//ch = '+';
	//printf("%d %d %d\n", sizeof(3.14), sizeof(0), sizeof('4'));
	//putchar(ch);
	
	//printf("\?"); // ����ĸ��

	/*
	ת���ַ���
	1���ɼ��ַ� ' " \ ?
	2�����ɼ��ַ� ASCII��ֵ0��7~13���ַ�
	3���˽��ƺ�ʮ������  \176  \x7e
	*/
	return 0;
}
