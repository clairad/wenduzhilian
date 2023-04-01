#include <stdio.h>

int main()
{
	int a[20] = {1,2,3,4,5,6,7,8,9,10};
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]); //Êý×é±éÀú
	}
	return 0;
}
