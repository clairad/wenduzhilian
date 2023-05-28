#include <stdio.h>

static int g_i;
void func()
{
	static int s_i = 0;
	s_i++;
	printf("%d ", s_i);
}

int main()
{
	func();
	func();
	func();
	func();

	while (1)
	{
		int i;
		scanf("%d", &i);

		while (getchar() != '\n');
		//getchar();
		printf("%d", i);
	}
	return 0;
}
