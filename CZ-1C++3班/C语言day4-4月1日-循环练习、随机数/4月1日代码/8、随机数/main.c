#include <stdio.h>
#include <time.h>

//typedef double lfloat;

int main()
{
	time_t tm;

	while(1)
	{ 
		tm = time(NULL); //timestamp ʱ��� 1970��1��1�� 0:0:0 time(&tm)
		//printf("%2d:%2d:%2d\n", tm / 3600 % 24, tm / 60 % 60, tm % 60);

		puts(ctime(&tm));
	}

	return 0;
}
