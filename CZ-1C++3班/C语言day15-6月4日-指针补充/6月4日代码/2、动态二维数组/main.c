#include <stdio.h>
#include <stdlib.h>

int mallocForm(int*** pform, int m, int n)
{
	*pform = (int**)malloc(n * sizeof(int*));
	int i;
	for (i = 0; i < n; i++)
	{
		(*pform)[i] = (int*)malloc(m * sizeof(int));
	}
}

void freeForm(int** form, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		free(form[i]);
	}
	free(form);
}

int main()
{
	int** form;
	int n, m;
	scanf("%d%d", &n, &m);

	//mallocForm(&form, n, m);
	form = (int**)malloc(n * sizeof(int*));
	int i;
	for (i = 0; i < n; i++)
	{
		form[i] = (int*)malloc(m * sizeof(int));
	}

	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			form[i][j] = m * i + j + 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%2d", form[i][j]);
		}
		putchar('\n');
	}

	freeForm(form, n);
	return 0;
}
