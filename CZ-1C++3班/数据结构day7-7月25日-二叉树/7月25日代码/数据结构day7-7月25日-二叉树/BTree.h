#ifndef _BTREE_H_
#define _BTREE_H_

typedef char BTDataType; //声明待存储的数据类型
typedef struct BTreeNode {
	BTDataType data;
	struct BTreeNode* lChild;
	struct BTreeNode* rChild;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, BTDataType end);
void BinaryTreeDestory(BTNode* root);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeGetDeep(BTNode* root);
BTNode* BinaryTreeGetCp(int n);


#endif //_BTREE_H_
