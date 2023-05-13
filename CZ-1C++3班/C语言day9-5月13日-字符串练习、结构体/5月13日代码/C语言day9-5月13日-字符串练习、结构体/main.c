#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print(int a[][7], int m, int n)
{
	int i, j, k;
	for (i = 0; i < m / 2; i++)
	{
		for (j = i; j < n - 1 - i; j++)
		{
			printf("%d ", a[i][j]);
		}

		for (k = i; k < m - 1 - i; k++)
		{
			printf("%d ", a[k][j]);
		}

		for (; j > i; j--)
		{
			printf("%d ", a[k][j]);
		}

		for (; k > i; k--)
		{
			printf("%d ", a[k][j]);
		}
	}
	if (m % 2)
	{
		for (j = i; j < n - i; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}

int testQ1()
{
	int a[5][7];

	int i;
	for (i = 0; i < 35; i++)
	{
		//a[i / 5][i % 5] = i + 1;
		((int*)a)[i] = i + 1;
	}

	print(a, 5, 7);
	return 0;
}

int m_strncasecmp(const char* s1, const char* s2, size_t n)
{
	int i;
	char ts1, ts2;
	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		ts1 = s1[i];
		ts2 = s2[i];
		if (isupper(ts1))
		{
			ts1 += 'a' - 'A';
		}
		if (isupper(ts2))
		{
			ts2 += 'a' - 'A';
		}
		if (ts1 > ts2)
		{
			return 1;
		}
		else if (ts1 < ts2)
		{
			return -1;
		}
	}
	if(i < n)
	{ 
		ts1 = s1[i];
		ts2 = s2[i];
		if (isupper(ts1))
		{
			ts1 += 'a' - 'A';
		}
		if (isupper(ts2))
		{
			ts2 += 'a' - 'A';
		}
		if (ts1 > ts2)
		{
			return 1;
		}
		else if (ts1 < ts2)
		{
			return -1;
		}
	}
	return 0;
}

char* m_strrstr(const char* src, const char *find)
{
	int i, j;
	char* res = NULL;

	for (i = 0; src[i]; i++)
	{
		if (src[i] == find[0])
		{
			for (j = 1; find[j]; j++)
			{
				if (src[i + j] != find[j])
				{
					break;
				}
			}
			if (!find[j])
			{
				res = src + i;
			}
		}
	}
	return res;
}

double m_atof(char* src)
{
	while (*src <= ' ')
	{
		src++;
	}

	int minusFlag = 1;
	if (*src == '-')
	{
		minusFlag = -1;
		src++;
	}

	int i;
	int sum1 = 0;
	double sum2 = 0, tmp = 1;
	for (i = 0; isdigit(src[i]); i++)
	{
		sum1 = sum1 * 10 + src[i] - '0';
	}
	if (src[i] == '.')
	{
		for (i++ ; isdigit(src[i]); i++)
		{
			tmp /= 10;
			sum2 += tmp * (src[i] - '0');
		}
	}
	return (sum1 + sum2) * minusFlag;
}

int longestWord(const char* src)
{
	int gap;
	int maxgap = 0;
	char* lasttmp;

	char* tmp = strchr(src, ' ');
	lasttmp = src;
	while (tmp)
	{
		gap = tmp - lasttmp;
		if (gap > maxgap)
		{
			maxgap = gap;
		}

		lasttmp = tmp + 1;
		tmp = strchr(tmp + 1, ' ');
	}
	gap = strlen(lasttmp);
	return maxgap > gap ? maxgap : gap;
}

void reverseWord(char* start, char* end)
{
	char* pi = start;
	char* pj = end - 1;
	char tmp;
	for (; pi < pj; pi++, pj--)
	{
		tmp = *pi;
		*pi = *pj;
		*pj = tmp;
	}
}

char* strrcpy(char* dst, const char* src)
{
	strcpy(dst, src);

	int i;
	int start = 0, end;
	for (i = 0; dst[i]; i++)
	{
		if (dst[i] == ' ')
		{
			end = i;
			reverseWord(dst + start, dst + end);
			start = i + 1;
		}
	}
	reverseWord(dst + start, dst + i);
	reverseWord(dst, dst + i);
	return dst;
}

int main()
{
	printf("%f\n", m_atof("   -12.456789"));

	printf("%d\n", m_strncasecmp("AbC", "aBcdef", 3));
	printf("%s\n", m_strrstr("abcdefgabcdefgabcd", "efg"));
	printf("%d\n", longestWord("This fat guy called C is very interesting"));
	char res[100];
	printf("%s\n", strrcpy(res, "I love you so much"));
	return 0;
}
