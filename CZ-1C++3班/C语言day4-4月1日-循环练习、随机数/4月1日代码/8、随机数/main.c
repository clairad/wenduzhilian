#include <stdio.h>
#include <time.h>

//typedef double lfloat;

int main()
{
	time_t tm;

	while(1)
	{ 
		tm = time(NULL); //timestamp 时间戳 1970年1月1日 0:0:0 time(&tm)
		//printf("%2d:%2d:%2d\n", tm / 3600 % 24, tm / 60 % 60, tm % 60);

		puts(ctime(&tm));
	}

	return 0;
}
