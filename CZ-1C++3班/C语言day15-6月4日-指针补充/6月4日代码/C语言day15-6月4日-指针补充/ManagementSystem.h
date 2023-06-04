#ifndef _MANSYS_H_
#define _MANSYS_H_

enum {
	EXIT = 0,
	ADD,
	DISPLAY,
	SORT_BY_NAME,
	SORT_BY_SCORE,
	SEARCH,
	AVERAGE
};

typedef struct {
	int no;
	char name[32];
	int age;
	int score[3];
	int alls;
}STU;

typedef struct {
	int size;
	int capacity;
	STU* alldata;
}Allmsg;

int load(const char* fileName, int* psize, int* pcapacity, STU** pdata);
void save(const char* fileName, int size, int capacity, STU* data);

#endif //_MANSYS_H_