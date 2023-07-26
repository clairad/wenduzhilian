#ifndef _STACK_H_
#define _STACK_H_

#include "vector.h"

typedef VTDataType STDataType;
typedef struct Stack {
	Vector data;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);


#endif //_STACK_H_
