#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100] = "pangzi";
	char str2[] = "Cpang";

	//printf("%d %d", strlen(str), sizeof(str));
	//printf("%s", strncpy(str1, str2, 5));
	printf("%s\n", strncat(str1, str2, 3));

	char s1[] = "abcde";
	char s2[] = "ABC";

	printf("%d", strncasecmp(s1, s2, 3));
	return 0;
}
