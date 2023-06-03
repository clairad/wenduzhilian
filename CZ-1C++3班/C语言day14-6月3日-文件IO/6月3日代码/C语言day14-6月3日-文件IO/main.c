#include <stdio.h>
#include <string.h>

char* itostr(int n)
{
	static char s_res[1024];
	int i;

	for (i = 31; i >= 0; i--)
	{
		if(n & 1 << i)
		{ 
			if (i > 1)
			{
				strcat(s_res, "2(");
				itostr(i);
				strcat(s_res, ")");
			}
			else if (i == 1)
			{
				strcat(s_res, "2");
			}
			else if (i == 0)
			{
				strcat(s_res, "2(0)");
			}
			strcat(s_res, "+");
		}
	}
	s_res[strlen(s_res) - 1] = '\0';
	return s_res;
}

int q1()
{
	int n;
	scanf("%d", &n);

	puts(itostr(n));
	/*int i;
	memset(&i, 1, sizeof(int));
	printf("%08x\n", i);
	char str[128];
	memset(str, 'a', sizeof(str) - 1);
	puts(str);*/
	return 0;
}

#define __in
#define __out
#define LETTERSUM 26

int hack(char* __in src, char* __in pwd, char* __out form)
{
	int nums = 0, nump = 0;
	memset(form, 0, LETTERSUM);

	int i;
	for (i = 0; src[i]; i++)
	{
		if (form[src[i] - 'A'] && form[src[i] - 'A'] != pwd[i])
		{
			return 1;
		}
		nums |= 1 << src[i] - 'A';
		nump |= 1 << pwd[i] - 'A';
		form[src[i] - 'A'] = pwd[i];
	}
	return nums != 0x3ffffff || nump != 0x3ffffff;
}

int main()
{
	char src[128];
	char pwd[128];
	char str[128];
	char form[LETTERSUM];
	scanf("%s%s%s", src, pwd, str);
	if (hack(src, pwd, form))
	{
		puts("Failed");
	}
	else
	{
		int i;
		for (i = 0; str[i]; i++)
		{
			putchar(form[str[i] - 'A']);
		}
	}
	
	return 0;
}


