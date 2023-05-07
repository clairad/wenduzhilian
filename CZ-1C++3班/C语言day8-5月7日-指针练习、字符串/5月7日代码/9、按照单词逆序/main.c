#include <stdio.h>
#include <string.h>

char *reverseString(char* dst, const char* src)
{
	char cp[100];
	strcpy(cp, src);
	//i think so
	char* tmp = strrchr(cp, ' ');
	while (tmp)
	{
		strcat(dst, tmp + 1);
		strcat(dst, " ");
		*tmp = '\0';
		tmp = strrchr(cp, ' ');
	}
	strcat(dst, cp);
	return dst;
}

int main()
{
	char str[] = "This fat guy called C is very interesting";
	char dst[100] = "";

	puts(reverseString(dst, str));
	return 0;
}
