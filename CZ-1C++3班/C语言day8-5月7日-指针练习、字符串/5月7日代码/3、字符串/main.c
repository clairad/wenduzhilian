#include <stdio.h>

int main()
{
	char s1[] = "abcjiofaooajopjoiai";
	char str1[16];
	char str2[16];
	char str3[16];

	scanf("%s%s%s", str1, str2, str3);
	puts(str1);
	puts(str2);
	puts(str3);

	int i;
	for (i = 0; s1[i]; i++) //×Ö·û´®±éÀú
	{
		putchar(s1[i]);
	}

	return 0;
}
