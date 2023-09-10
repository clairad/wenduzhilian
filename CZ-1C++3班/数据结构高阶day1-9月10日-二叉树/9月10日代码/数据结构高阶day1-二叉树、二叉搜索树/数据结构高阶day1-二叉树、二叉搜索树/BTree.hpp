#pragma once
#include <iostream>
#include <queue>
#include <stack>
using std::cout;
using std::queue;
using std::stack;

namespace Cpang {

	template <typename T>
	class BTreeNode
	{
		T data;

		BTreeNode<T>* lChild;
		BTreeNode<T>* rChild;
	public:
		BTreeNode(const T& o = T()) :
			data(o), lChild(nullptr), rChild(nullptr)
		{}

		template <typename X>
		friend class BTree;
	};

	template <typename T>
	class BTree
	{
		BTreeNode<T>* root;

		int pos;
		BTreeNode<T>* makeTree(T src[], const T& sign)
		{
			if (src[pos] == sign)
			{
				pos++;
				return nullptr;
			}

			BTreeNode<T>* cur = new BTreeNode<T>(src[pos]);
			pos++;

			cur->lChild = makeTree(src, sign);
			/*if (cur->lChild)
			{
				cur->lChild->Parent = cur;
			}*/
			cur->rChild = makeTree(src, sign);

			return cur;
		}

		void destroy(BTreeNode<T>* cur)
		{
			if (cur)
			{
				destroy(cur->lChild);
				destroy(cur->rChild);
				delete cur;
			}
		}

		void preOrder(BTreeNode<T>* cur)
		{
			if (cur)
			{
				cout << cur->data << ' ';
				preOrder(cur->lChild);
				preOrder(cur->rChild);
			}
		}

		void inOrder(BTreeNode<T>* cur)
		{
			if (cur)
			{
				inOrder(cur->lChild);
				cout << cur->data << ' ';
				inOrder(cur->rChild);
			}
		}

		void lastOrder(BTreeNode<T>* cur)
		{
			if (cur)
			{
				lastOrder(cur->lChild);
				lastOrder(cur->rChild);
				cout << cur->data << ' ';
			}
		}
	public:
		BTree(T src[], const T& sign)
		{
			pos = 0;
			root = makeTree(src, sign);
		}

		~BTree()
		{
			destroy(root);
		}

		void printPreOrder()
		{
			preOrder(root);
		}

		void printInOrder()
		{
			inOrder(root);
		}

		void printLastOrder()
		{
			lastOrder(root);
		}

		void printLevelOrder()
		{
			queue<BTreeNode<T>*> qu;
			BTreeNode<T>* cur;
			qu.push(root);
			while (!qu.empty())
			{
				cur = qu.front();
				cout << cur->data << ' ';
				if (cur->lChild)
				{
					qu.push(cur->lChild);
				}
				if (cur->rChild)
				{
					qu.push(cur->rChild);
				}
				qu.pop();
			}
		}

		void printPreOrderNR()
		{
			stack<BTreeNode<T>*> st;
			BTreeNode<T>* cur = root;

			while (1)
			{
				cout << cur->data << ' ';
				if (cur->rChild)
				{
					st.push(cur->rChild);
				}
				if (cur->lChild)
				{
					cur = cur->lChild;
				}
				else
				{
					if (st.empty())
					{
						break;
					}
					cur = st.top();
					st.pop();
				}
			}
		}

		void printInOrderNR()
		{
			stack<BTreeNode<T>*> st;
			BTreeNode<T>* cur = root;

			while (1)
			{
				for (; cur; cur = cur->lChild)
				{
					st.push(cur);
				}

				if (st.empty())
				{
					break;
				}
				cur = st.top();
				cout << cur->data << ' ';
				st.pop();
				cur = cur->rChild;
			}
		}

		void printLastOrderNR()
		{
			stack<BTreeNode<T>*> stn;
			BTreeNode<T>* cur = root;
			stack<bool> stf;

			while (1)
			{
				for (; cur; cur = cur->lChild)
				{
					stn.push(cur);
					stf.push(false);
				}

				while (stf.top())
				{
					cur = stn.top();
					cout << cur->data << ' ';
					stf.pop();
					stn.pop();
					if (stn.empty())
					{
						return;
					}
				}

				if (stf.top() == false)
				{
					stf.top() = true;
					cur = stn.top()->rChild;
				}
			}
		}
	};

};