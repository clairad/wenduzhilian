#include <stdio.h>
#include <string.h>

char * strrcpy(char *dst, const char *src)
{
	int len = strlen(src);
	int i;
	for (i = 0; i < len; i++)
	{
		dst[i] = src[len - 1 - i];
	}
	return dst;
}

int getEachWord(char *str, char astr[][100])
{
	int i = 0;
	char* lasttmp = str;
	char* tmp = strchr(str, ' ');
	while (tmp)
	{
		strncpy(astr[i], lasttmp, tmp - lasttmp);
		i++;
		lasttmp = tmp + 1;
		tmp = strchr(tmp + 1, ' ');
	}
	strcpy(astr[i], lasttmp);
	return i + 1;
}

void bubbleSort(char astr[][100], int n)
{
	int i, j;
	char tmp[100];
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(astr[j], astr[j + 1]) > 0)
			{
				strcpy(tmp, astr[j]);
				strcpy(astr[j], astr[j + 1]);
				strcpy(astr[j + 1], tmp);
			}
		}
	}
}

char* catAllStr(char astr[][100], int n, char* res)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		strcat(res, astr[i]);
		strcat(res, " ");
	}
	strcat(res, astr[i]);
	return res;
}

int main()
{
	char str[1000];
	char astr[100][100] = { 0 };
	char res[1000] = "";

	scanf("%999[^\n]", str);
	int len = getEachWord(str, astr);
	bubbleSort(astr, len);
	puts(catAllStr(astr, len, res));
	
	return 0;
}
