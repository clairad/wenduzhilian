#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE* fp = fopen("1.txt", "r");
	

#if 0 //fgets
	char str[1024] = "";
	int tmp = 0;
	while(1)
	{ 
		if (!fgets(str, 1024, fp))
		{
			break;
		}
		printf("%s", str);
	}
#elif 0 //fgetc
	char ch;
	while (1)
	{
		if ((ch = fgetc(fp)) == EOF)
		{
			break;
		}
		putchar(ch);
	}
#else //fread
	char str[1024] = "";
	while (1)
	{
		if (!fread(str, 1023, sizeof(char), fp))
		{
			break;
		}
		printf("%s", str);
		Sleep(500);
	}
#endif

	fclose(fp);
	return 0;
}
