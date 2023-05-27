#include <stdio.h>
#define ASSERT(cond, ...) if( !(cond) )\
{printf( "assertion error line %d, file(%s) %s %s\n", \
__LINE__, __FILE__ , __VA_ARGS__, __VA_ARGS__);}

int main()
{
	printf("%s\n%s\n%d\n", __TIME__, __FILE__, __LINE__);
#ifdef __TEST__
#line 100 "1.c"
	printf("%s\n%s\n%d\n", __TIME__, __FILE__, __LINE__);
#endif
	ASSERT(0, "undefined error", " 123");
	return 0;
}
