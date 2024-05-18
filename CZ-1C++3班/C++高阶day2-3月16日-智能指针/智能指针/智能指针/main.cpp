#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;

template <class T>
class SmartPtr
{
	T* _ptr;
public:
	SmartPtr(T* ptr = nullptr) : _ptr(ptr) {}
	~SmartPtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
		_ptr = nullptr;
	}
};


struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode() { cout << "~ListNode()" << endl; }
};

int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	return 0;
}