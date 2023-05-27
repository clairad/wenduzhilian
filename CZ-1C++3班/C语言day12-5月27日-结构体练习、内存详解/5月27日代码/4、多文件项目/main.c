#include <stdio.h>
#include "st.h"
int g_i;

int main()
{
	/*printf("%d", add(1, 3));
	printf(" %d\n", g_i);
	printf("%d", add(1, 3));
	printf(" %d\n", g_i);
	printf("%d", add(1, 3));
	printf(" %d\n", g_i);*/
	printf("%d", test());
	g_i++;
	printf("%d\n\n", g_i);
	return 0;
}
