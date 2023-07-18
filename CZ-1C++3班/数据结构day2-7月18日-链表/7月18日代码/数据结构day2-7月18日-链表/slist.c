#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

void SListInit(SList* plt)
{
	plt->head = NULL;
	plt->size = 0;
}

void SListDestory(SList* plt)
{
	while (plt->head)
	{
		SListPopFront(plt);
	}
}

SListNode* BuySListNode(SLDataType x)
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->next = NULL;
	cur->data = x;
	return cur;
}

void SListPushFront(SList* plt, SLDataType x)
{
	SListNode* cur = BuySListNode(x);
	cur->next = plt->head;
	plt->head = cur;
	plt->size++;
}

void SListPopFront(SList* plt)
{
	SListNode* tmp = plt->head;
	plt->head = plt->head->next;
	free(tmp);
	plt->size--;
}

SListNode* SListFind(SList* plt, SLDataType x)
{
	SListNode* cur;
	for (cur = plt->head; cur; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

SListNode* SListFindPre(SList* plt, SLDataType x)
{
	SListNode* cur;
	for (cur = plt->head; cur->next; cur = cur->next)
	{
		if (cur->next->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void SListInsert(SList* plt, SListNode* pos, SLDataType x)
{
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next = cur;
	plt->size++;
}

void SListErase(SList* plt, SListNode* pos)
{
	SListNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	plt->size--;
}

void SListRemove(SList* plt, SLDataType x)
{
	if (plt->head->data == x)
	{
		SListPopFront(plt);
		return;
	}
	SListNode * cur = SListFindPre(plt, x);
	if (cur)
	{
		SListErase(plt, cur);
	}
}

void SListModify(SList* plt, SLDataType x1, SLDataType x2)
{
	SListNode* cur = SListFind(plt, x1);
	if (cur)
	{
		cur->data = x2;
	}
}

void SListPrint(SList* plt)
{
	SListNode* cur;
	for (cur = plt->head; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	puts("NULL");
}

void SListSort(SList* plt)
{
	SListNode* newHead = (SListNode*)malloc(sizeof(SListNode));
	newHead->next = NULL;
	SListNode* tmp, *cur;

	while (plt->head)
	{
		tmp = plt->head;
		plt->head = plt->head->next;

		for (cur = newHead; cur->next; cur = cur->next)
		{
			if (cur->next->data > tmp->data)
			{
				break;
			}
		}

		tmp->next = cur->next;
		cur->next = tmp;
	}
	plt->head = newHead->next;
	free(newHead);
}

void SListReverse(SList* plt)
{
#if 0
	SListNode* tmp = NULL, *cur = plt->head;
	while (cur)
	{
		plt->head = plt->head->next;
		cur->next = tmp;
		tmp = cur;
		cur = plt->head;
	}
	plt->head = tmp;
#elif 1
	SListNode* tmp = plt->head->next, * cur = plt->head;
	while (tmp)
	{
		cur->next = tmp->next;
		tmp->next = plt->head;
		plt->head = tmp;
		tmp = cur->next;
	}
#else
	SListNode* tmp = plt->head->next, * cur = plt->head;
	plt->head->next = NULL;
	while (tmp)
	{
		plt->head = tmp;
		tmp = plt->head->next;
		plt->head->next = cur;
		cur = plt->head;
	}
#endif
}

void SListMerge(SList* plt, SList* plt2)
{
	SListNode* headC = (SListNode*)malloc(sizeof(SListNode));
	headC->next = NULL;
	SListNode* tail = headC;
	SListNode* headA = plt->head;
	SListNode* headB = plt2->head;
	SListNode* cur;

	while (headA && headB)
	{
		if (headA->data < headB->data)
		{
			cur = headA;
			headA = headA->next;
		}
		else
		{
			cur = headB;
			headB = headB->next;
		}
		tail->next = cur;
		tail = cur;
	}
	if (headA)
	{
		tail->next = headA;
	}
	if (headB)
	{
		tail->next = headB;
	}

	plt->size += plt2->size;
	plt->head = headC->next;
	plt2->head = NULL;
	plt2->size = 0;
	free(headC);
}

