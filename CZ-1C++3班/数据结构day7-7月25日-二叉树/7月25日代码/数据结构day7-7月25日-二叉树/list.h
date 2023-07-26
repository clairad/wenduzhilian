#ifndef _LIST_H_
#define _LIST_H_
#include "BTree.h"

typedef BTNode* LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

typedef struct List {
	ListNode* head;
	int size;
}List;

void ListInit(List* plt); //初始化
void ListDestory(List *plt); //销毁

ListNode* BuyListNode(LTDataType x); //获取新节点
void ListPushFront(List *plt, LTDataType x); //头插
void ListPopFront(List *plt); //头删
void ListPushBack(List* plt, LTDataType x); //尾插
void ListPopBack(List* plt); //尾删
ListNode *ListFind(List *plt, LTDataType x); //查找
void ListInsert(List* plt, ListNode *pos, LTDataType x); //插入
void ListErase(List* plt, ListNode *pos); //删除（位置）
void ListRemove(List *plt, LTDataType x); //删除（数据）
void ListModify(List* plt, ListNode* pos, LTDataType x); //修改
void ListPrint(List *plt);  //打印


#endif //_LIST_H_
