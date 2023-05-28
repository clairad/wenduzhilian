#include <stdio.h>

int feb(int n, int *pres)
{
	static int s_count = 0;
	s_count++;
	*pres = s_count;
	if (n <= 2)
	{
		return 1;
	}
	return feb(n - 1, pres) + feb(n - 2, pres);
}

void hanoi(int n, char a, char b, char c)
{
	static int s_i = 1;
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("%4d:%dºÅÅÌ´Ó%cÖùÒÆ¶¯µ½%cÖù\n", s_i, n, a, c);
		s_i++;
		hanoi(n - 1, b, a, c);
	}
}

int main()
{
	/*int n;
	printf("%d\n", feb(25, &n));
	printf("%d", n);*/

	hanoi(10, 'a', 'b', 'c');
	return 0;
}
