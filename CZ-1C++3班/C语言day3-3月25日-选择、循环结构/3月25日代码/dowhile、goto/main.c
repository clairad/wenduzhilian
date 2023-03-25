#include <stdio.h>

int main()
{
	int i = 0;

A:
	printf("%d ", i);
	i++;
	if (i < 10)
	{
		goto A;
	}

	return 0;
}

int main1()
{
	do {

	} while (0);

	return 0;
}
/*
int XXX()
{
	do {

	int ret = func1();
	if (ret)
	{
		break;
	}
	int ret = func2();
	if (ret)
	{
		goto error;
	}
	int ret = func3();
	if (ret)
	{
		goto error;
	}

	} while (0);
error:
	//
}

*/