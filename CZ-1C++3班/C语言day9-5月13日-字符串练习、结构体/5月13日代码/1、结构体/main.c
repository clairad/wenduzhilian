#include <stdio.h>

struct Student{
	char name[28];
	int no;
	int age;
	int score[4];
};

struct Test{
	char c1;
	double f;
	int i;
};

//ÈáÐÔÊý×é
struct Data {
	int n;
	int value[0];
};

//int add(int, int);
//extern int i;

int main()
{
	struct Student xiaoming = { "xiaoming", 20, 27, {74, 83, 92, 56}};
	struct Student* pxiaoming = &xiaoming;

	printf("%d\n", xiaoming.age);
	printf("%s\n", pxiaoming->name);
	printf("%d\n", sizeof(struct Test));

	struct Data* pv1 = (struct Data*)malloc(sizeof(struct Data) + 100 * sizeof(int));

	return 0;
}
