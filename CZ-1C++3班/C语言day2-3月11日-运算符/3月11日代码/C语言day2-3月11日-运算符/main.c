#include <stdio.h>

int main()
{
	int a = -9;
	long long b = -9;
	float f = 3.14;
	unsigned int i = 6;
	if (a + i < 0)
	{
		printf("���з��ſ���\n");
	}
	else
	{
		printf("���޷��ſ���\n");
	}

	printf("%lld\n", sizeof(a + b));
	printf("%lld\n", sizeof(f + b));
	return 0;
}
//�����򸡵��Ϳ���
//�����������Ϳ���
//�з������޷��ſ���