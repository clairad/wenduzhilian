#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plt)
{
	plt->head = (ListNode*)malloc(sizeof(ListNode));
	plt->head->next = plt->head->prev = plt->head;
	plt->size = 0;
}

void ListDestory(List* plt)
{
	while (plt->head->next != plt->head)
	{
		ListPopFront(plt);
	}
	free(plt->head);
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode * tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = x;
	tmp->prev = tmp->next = NULL;
	return tmp;
}

void ListPushFront(List* plt, LTDataType x)
{
	ListInsert(plt, plt->head, x);
}

void ListPopFront(List* plt)
{
	ListErase(plt, plt->head->next);
}

void ListPushBack(List* plt, LTDataType x)
{
	ListInsert(plt, plt->head->prev, x);
}

void ListPopBack(List* plt)
{
	ListErase(plt, plt->head->prev);
}

ListNode* ListFind(List* plt, LTDataType x)
{
	ListNode* cur;
	for (cur = plt->head->next; cur != plt->head; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void ListInsert(List* plt, ListNode* pos, LTDataType x)
{
	ListNode* cur = BuyListNode(x);
	ListNode* tmp = pos->next;

	pos->next = cur;
	cur->prev = pos;

	cur->next = tmp;
	tmp->prev = cur;
	plt->size++;
}

void ListErase(List* plt, ListNode* pos)
{
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	plt->size--;
}

void ListRemove(List* plt, LTDataType x)
{
	ListNode* cur = ListFind(plt, x);
	if (cur)
	{
		ListErase(plt, cur);
	}
}

void ListModify(List* plt, ListNode* pos, LTDataType x)
{
	pos->data = x;
}

void ListPrint(List* plt)
{
	ListNode* cur;
	printf("head<->");
	for (cur = plt->head->next; cur != plt->head; cur = cur->next)
	{
		printf("%d<->", cur->data);
	}
	puts("head");
}
