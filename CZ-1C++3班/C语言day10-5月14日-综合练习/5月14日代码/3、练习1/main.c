#include <stdio.h>
#include <ctype.h>

int getSum(const char* src)
{
	int i;
	int tmp = 0, sum = 0;
	for (i = 0; src[i]; i++)
	{
		if (isdigit(src[i]))
		{
			tmp = tmp * 10 + src[i] - '0';
		}
		else
		{
			sum += tmp;
			tmp = 0;
		}
	}
	return sum;
}

typedef struct {
	char ch;
	size_t num;
	size_t pos;
}letterMsg;

letterMsg continuousLetter(const char* src)
{
	int i;
	letterMsg res = {src[0], 1, 0};
	int max = 0;
	for (i = 1; src[i]; i++)
	{
		if (src[i] == src[i - 1])
		{
			res.num++;
		}
		else
		{
			if (max < res.num)
			{
				res.ch = src[i - 1];
				res.pos = i - res.num;
				max = res.num;
			}
			res.num = 1;
		}
	}
	if (max < res.num)
	{
		res.ch = src[i - 1];
		res.pos = i - res.num;
		max = res.num;
		res.num = 1;
	}
	res.num = max;
	return res;
}

int allLetter(const char* src)
{
	int res = 0;
	int i;
	for (i = 0; src[i]; i++)
	{
		if (isalpha(src[i]))
		{
			res |= 1 << (src[i] | 1 << 5) - 'a';
		}
	}

	return res == 0x3ffffff;
}

char* caesarPassword(char* dst, const char* src, int n)
{
	int i;
	for (i = 0; src[i]; i++)
	{
		dst[i] = (src[i] - 'a' + n) % 26 + 'a';
	}
	return dst;
}

int main()
{
	printf("%d\n", getSum("ui289hfuihaih7f81hf8"));

	letterMsg lm = continuousLetter("aaaaabbbbccccccccbbbbbaaaaaaaaaaa");
	printf("%c %lld %lld\n", lm.ch, lm.num, lm.pos);

	printf("%d\n", allLetter("abcdeFghijkLmnopqrsTuvwxyz"));
	char str[100] = "";
	printf("%s\n", caesarPassword(str, "abcdefghijklmnopqrstuvwxyz", 3));
	return 0;
}
