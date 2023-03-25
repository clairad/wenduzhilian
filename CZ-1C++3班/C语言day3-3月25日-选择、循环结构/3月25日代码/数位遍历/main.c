#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int sum = 0;
	for (i = n; i; i /= 2) //ÊıÎ»±éÀú
	{
		sum += i % 2;
	}

	printf("%d", sum);
	return 0;
}
