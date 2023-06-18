#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdio.h>
#include <stdlib.h>

//�������͡�
typedef int VTDataType; 

typedef struct Vector {
	VTDataType* array; // ָ��̬���ٵ�����
	size_t size ; // ��Ч���ݸ���
	size_t capicity ; // �����ռ�Ĵ�С
}Vector;

void VectorInit(Vector* psl, size_t capacity); //��ʼ��
void VectorDestory(Vector* psl); //����
void VectorPushBack(Vector* psl, VTDataType x); //β��
void VectorPopBack(Vector* psl); //βɾ
void VectorPushFront(Vector* psl, VTDataType x); //ͷ��
void VectorPopFront(Vector* psl); //ͷɾ
int  VectorFind(Vector* psl, VTDataType x); //����
void VectorInsert(Vector* psl, size_t pos, VTDataType x); //����
void VectorErase(Vector* psl, size_t pos); //ɾ����λ�ã�
void VectorRemove(Vector* psl, VTDataType x); //ɾ�������ݣ�
void VectorModify(Vector* psl, size_t pos, VTDataType x); //�޸�
void VectorPrint(Vector* psl);  //��ӡ
int  VectorEmpty(Vector* psl);
void VectorClear(Vector* psl);

void VectorSort(Vector* psl, int (*cmp)(VTDataType *a, VTDataType *b));
void VectorSearch(Vector* psl, VTDataType x);
void VectorRemoveAll(Vector* psl, VTDataType x); //ɾ��
void VectorMerge(Vector* src, Vector* val);
Vector VectorMergeNew(Vector* val1, Vector* val2);

#endif //_VECTOR_H_