#include <stdio.h>
#include <ctype.h>

int main()
{
	char str[128] = "";
	//char res[128] = "";
	fgets(str, 127, stdin);

	int i, j = 0;
	for (i = 0; str[i]; i++)
	{
		if(isalpha(str[i]))
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = 0;

	puts(str);
	return 0;
}
