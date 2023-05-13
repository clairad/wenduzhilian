#include <stdio.h>

//Î»¶Î Î»Óò
struct mtime {
	unsigned int week  : 3;
	unsigned int month : 4;
	unsigned int day   : 5;
	unsigned int hour  : 5;
	unsigned int min   : 6;
	unsigned int sec   : 6;
	unsigned int year  : 8;
};

int main()
{

	return 0;
}
