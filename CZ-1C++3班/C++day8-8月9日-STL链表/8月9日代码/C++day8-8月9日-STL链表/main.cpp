#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "list.hpp"
using namespace std;

class Test
{
public:
	int a;
	int b;
	int c;

	static int s;

	Test() {
		a = b = c = s;
		s++;
	}
};
int Test::s = 0;

int main()
{
	Cpang::List<int> ls1{ 2,3,5,6,9,12 };
	Cpang::List<int> ls2{ 1,4,7,8,10,11 };
	Cpang::List<int> ls3{ 7,8,4,1,9,6,5,3,2 };
	Cpang::List<int>::iterator it;
	ls1.merge(ls2);
	ls3.sort();

	for (it = ls1.begin(); it != ls1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl << ls1.size() << endl;
	cout << *ls1.find(5) << endl << ls2.size() << endl;


	Cpang::List<int>::reverse_iterator rit;
	for (rit = ls3.rbegin(); rit != ls3.rend(); rit++)
	{
		cout << *rit << ' ';
	}
	cout << endl << ls3.size() << endl;
	return 0;
}


int testlist()
{
	Cpang::List<Test> lst{ Test(), Test(), Test() };
	Cpang::List<Test> ls2(++lst.begin(), --lst.end());
	Cpang::List<Test>::iterator it = ls2.begin();

	cout << it->b << endl;
	ls2.push_back(Test());
	//ls2.push_front(1);
	//ls2.pop_back();
	//ls2.insert(it, 10);
	for (auto& e : ls2)
	{
		cout << e.a << ' ';
	}
	cout << endl << ls2.size() << endl;
	return 0;
}