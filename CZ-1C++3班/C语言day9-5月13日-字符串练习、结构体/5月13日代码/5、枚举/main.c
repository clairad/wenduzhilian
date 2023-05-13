#include <stdio.h>

enum WEEK{
	SUN,
	MON,
	TUE,
	WED,
	TUR,
	FRI,
	SAT,

	JAN = 1001,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};

int main()
{
	printf("%d", FRI);
	
	enum WEEK ew = JAN;

	switch (ew)
	{
	case SUN:
	}
	return 0;
}
