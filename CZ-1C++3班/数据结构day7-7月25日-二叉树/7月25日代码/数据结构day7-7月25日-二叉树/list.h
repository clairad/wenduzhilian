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

void ListInit(List* plt); //��ʼ��
void ListDestory(List *plt); //����

ListNode* BuyListNode(LTDataType x); //��ȡ�½ڵ�
void ListPushFront(List *plt, LTDataType x); //ͷ��
void ListPopFront(List *plt); //ͷɾ
void ListPushBack(List* plt, LTDataType x); //β��
void ListPopBack(List* plt); //βɾ
ListNode *ListFind(List *plt, LTDataType x); //����
void ListInsert(List* plt, ListNode *pos, LTDataType x); //����
void ListErase(List* plt, ListNode *pos); //ɾ����λ�ã�
void ListRemove(List *plt, LTDataType x); //ɾ�������ݣ�
void ListModify(List* plt, ListNode* pos, LTDataType x); //�޸�
void ListPrint(List *plt);  //��ӡ


#endif //_LIST_H_
