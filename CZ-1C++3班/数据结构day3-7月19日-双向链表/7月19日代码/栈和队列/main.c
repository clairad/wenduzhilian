#include <stdio.h>
//#include "stack.h"
//#include "queue.h"

struct Stack {
	char array[10001];
	int size;
}st = { 0 };

void push(struct Stack* pst, char n)
{
	pst->array[pst->size] = n;
	pst->size++;
}

void pop(struct Stack* pst)
{
	pst->size--;
}

char top(struct Stack* pst)
{
	return pst->array[pst->size - 1];
}

int empty(struct Stack* pst)
{
	return pst->size == 0;
}

int isValid(char* s)
{
	int i;
	char tmp;
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			push(&st, s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (empty(&st))
			{
				return 0;
			}
			tmp = top(&st);
			if (tmp == '(')
			{
				tmp--;
			}
			if (s[i] - tmp != 2)
			{
				return 0;
			}
			pop(&st);
		}
	}
	return empty(&st);
}

int main()
{
	printf("%d", isValid("{[]}"));
	return 0;
}
/*
int main1()
{
	Stack st;

	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d %d\n", StackTop(&st), StackSize(&st));
	StackPop(&st);
	printf("%d %d\n", StackTop(&st), StackSize(&st));
	StackPop(&st);
	printf("%d %d\n", StackTop(&st), StackSize(&st));
	StackPop(&st);
	printf("%d %d\n", StackTop(&st), StackSize(&st));
	StackPop(&st);
	printf("%d %d\n", StackTop(&st), StackSize(&st));

	StackDestory(&st);

	Queue qu;

	QueueInit(&qu);

	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);
	QueuePush(&qu, 5);
	printf("%d %d\n", QueueFront(&qu), QueueSize(&qu));
	QueuePop(&qu);
	printf("%d %d\n", QueueFront(&qu), QueueSize(&qu));
	QueuePop(&qu);
	printf("%d %d\n", QueueFront(&qu), QueueSize(&qu));
	QueuePop(&qu);
	printf("%d %d\n", QueueFront(&qu), QueueSize(&qu));
	QueuePop(&qu);
	printf("%d %d\n", QueueFront(&qu), QueueSize(&qu));

	QueueDestory(&qu);
	return 0;
}*/
