#include <stdio.h>

int main()
{
	char ch = getchar();
	
	//putchar(ch | 1 << 5); //��ĳһλǿ��д1
	//putchar(ch & ~(1 << 5)); //��ĳһλǿ��д0
	putchar(ch ^ 1 << 5); //�ı�ĳһλ��״̬
	
	return 0;
}
