#include "st.h"

static int add(int a, int b)
{
	g_i++;
	return a + a + b + b;
}

int test()
{
	return add(2, 5);
}