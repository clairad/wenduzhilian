#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	//freopen("data.txt", "w", stdout);
	FILE* pf = fopen("data.txt", "w");
	int n;
	scanf("%d", &n);

	fprintf(pf, "%d\n", n);
	int i;
	for (i = 0; i < n; i++)
	{
		fprintf(pf, "%d ", rand() % 10000);
	}

	fclose(pf);
	return 0;
}
