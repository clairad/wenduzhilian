#include <stdio.h>
#include "BTree.h"


int main()
{
	BTNode* root = BinaryTreeCreate("ABD**EH**I**CF**GJK**L***", '*');

	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');
	BinaryTreeLevelOrder(root);
	putchar('\n');
	BinaryTreePrevOrderNonR(root);
	putchar('\n');
	BinaryTreeInOrderNonR(root);
	putchar('\n');
	BinaryTreePostOrderNonR(root);
	putchar('\n');
	printf("%d\n", BinaryTreeGetDeep(root));

	BinaryTreeDestory(root);

	BTNode* root2 = BinaryTreeGetCp(10);
	BinaryTreePrevOrder(root2);
	putchar('\n');
	BinaryTreeInOrder(root2);
	putchar('\n');
	BinaryTreePostOrder(root2);
	putchar('\n');
	BinaryTreeLevelOrder(root2);
	putchar('\n');


	return 0;
}
