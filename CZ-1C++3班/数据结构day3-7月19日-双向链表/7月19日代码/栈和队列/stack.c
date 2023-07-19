#include "stack.h"

void StackInit(Stack* ps)
{
	VectorInit(&ps->data, 100);
}

void StackDestory(Stack* ps)
{
	VectorDestory(&ps->data);
}

void StackPush(Stack* ps, STDataType x)
{
	VectorPushBack(&ps->data, x);
}

void StackPop(Stack* ps)
{
	VectorPopBack(&ps->data);
}

STDataType StackTop(Stack* ps)
{
	return ps->data.array[ps->data.size - 1];
}

int StackEmpty(Stack* ps)
{
	return VectorEmpty(&ps->data);
}

int StackSize(Stack* ps)
{
	return ps->data.size;
}
