#include <stdio.h>

int main()
{
	int a = 321;
	char ch = a;
	//1 0100 0001
	//  0100 0001
	//�����͸������ͻ�ضϸ�λ
	printf("%d\n", ch);

	unsigned char ch2 = -1;
	int a2 = ch2;
	//�ֽ�������������λ���޷��žͲ�0

	printf("%d", a2);
	return 0;
}
