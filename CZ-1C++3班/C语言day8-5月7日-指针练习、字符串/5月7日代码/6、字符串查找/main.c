#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "wangfang";

	printf("%d\n", strchr(str, 'a') - str);
	printf("%d\n", strrchr(str, 'a') - str);
	printf("%d\n", strstr(str, "fa") - str);
	printf("%d\n", strpbrk(str, "gnf") - str);
	return 0;
}
