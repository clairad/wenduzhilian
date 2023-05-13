#include <stdio.h>
#include <time.h>

int main()
{
	time_t t;
	time(&t);
	printf("%s", ctime(&t));
	struct tm* st = localtime(&t); 

	const char* week[7] = {"日", "一", "二", "三", "四", "五", "六"};
	printf("%d年%d月%d日 %d:%d:%d 星期%s",
			st->tm_year + 1900 ,
			st->tm_mon + 1, 
			st->tm_mday, 
			st->tm_hour,
			st->tm_min,
			st->tm_sec,
			week[st->tm_wday]);

	return 0;
}
