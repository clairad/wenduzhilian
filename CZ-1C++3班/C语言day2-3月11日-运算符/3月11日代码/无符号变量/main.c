#include <stdio.h>

int main()
{
	//unsigned //�������ͱ���ǰ����ʾ�������޷��ţ�û�з���λ��
	unsigned int uc;
	auto signed short int s;
	uc = -1;
	if (uc < 0) //���
	{
		printf("ucС��0");
	}
	//scanf("%u", &uc);
	printf("%x", uc);
	return 0;
}
