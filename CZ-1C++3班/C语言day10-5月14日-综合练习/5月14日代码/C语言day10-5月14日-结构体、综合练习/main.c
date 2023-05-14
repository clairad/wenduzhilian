#include <stdio.h>
#include <string.h>

char * itoa(char* res, long long n, int m)
{
	char tmp[65] = "";
	long long i;
	int j = 63;
	const char* str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int minusflag = 1;
	if (n < 0)
	{
		n *= -1;
		minusflag = -1;
	}
	for (i = n; i; i /= m)
	{
		tmp[j] = str[i % m];
		j--;
	}
	if (minusflag)
	{
		tmp[j] = '-';
		j--;
	}
	strcpy(res, tmp + j + 1);
	return res;
}

int main()
{
	char str[65];

	itoa(str, -9223372036854775807ll, 2);
	puts(str);
	return 0;
}
