#include <stdio.h>
#include <stdlib.h>

enum{
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

typedef struct{
	int size;
	int capacity;
	STU* alldata;
}Allmsg;

void check(Allmsg* pallstu)
{
	if (pallstu->size == pallstu->capacity)
	{
		pallstu->capacity *= 2;
		pallstu->alldata = (STU*)realloc(pallstu->alldata, pallstu->capacity * sizeof(STU));
	}
}

void inputMsg(STU* src)
{
	scanf("%s %d %d %d %d\n",
		src->name,
		&src->age,
		&src->score[0],
		&src->score[1],
		&src->score[2]);
	src->alls = src->score[0] + src->score[1] + src->score[2];
}

void displayStu(Allmsg allstu)
{
	int i;
	for (i = 0; i < allstu.size; i++)
	{
		printf("%d %s %d %d %d %d\n",
			allstu.alldata[i].no,
			allstu.alldata[i].name,
			allstu.alldata[i].age,
			allstu.alldata[i].score[0],
			allstu.alldata[i].score[1],
			allstu.alldata[i].score[2]);
	}
}

int main()
{
	int op;
	Allmsg allstu = {0, 32};
	allstu.alldata = (STU*)malloc(allstu.capacity * sizeof(STU));
	while (1)
	{
		scanf("%d", &op);
		switch (op)
		{
		case EXIT:
			free(allstu.alldata);
			return 0;
		case ADD:
			check(&allstu);
			inputMsg(&allstu.alldata[allstu.size]);
			if (allstu.size == 0)
			{
				allstu.alldata[allstu.size].no = 1;
			}
			else
			{
				allstu.alldata[allstu.size].no = allstu.alldata[allstu.size - 1].no + 1;
			}
			allstu.size++;
			break;
		case DISPLAY:
			displayStu(allstu);
			break;
		case SORT_BY_NAME:
		case SORT_BY_SCORE:
		case SEARCH:
		case AVERAGE:;
		}
	}
	free(allstu.alldata);
	return 0;
}
