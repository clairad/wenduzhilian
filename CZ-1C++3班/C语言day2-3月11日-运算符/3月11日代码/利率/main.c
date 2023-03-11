#include <stdio.h>

int main()
{
	double money, salary;

	scanf("%lf%lf", &money, &salary);
	printf("%.2lf", money * (1 + salary));
	return 0;
}
