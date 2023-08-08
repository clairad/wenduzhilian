#include <iostream>
#include "vector.h"
using Cpang::Vector;
using namespace std;

//左值：可以放在赋值运算符左边的叫左值
//右值：只能放在赋值运算符右边的叫右值
//引用只可以接左值，const引用才可以接右值
//[] * -> .  C++中()在返回引用的时候可以做左值

int main()
{
	Vector<Vector<int> > vvi(5, Vector<int>(5)); //留一个空格

	/*Vector<int> itmp;
	int i, j, tmp;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cin >> tmp;
			itmp.push_back(tmp);
		}
		vvi.push_back(itmp);
		itmp.clear();
	}*/
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			vvi[i][j] = i * 5 + j;
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << vvi[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}


int vectortest()
{
	Cpang::Vector<int> vi(14); //{7, 4, 1, 8, 5, 2, 9, 6, 3, 'A'};

	int i;
	for (i = 0; i < 14; i++)
	{
		vi[i] = i;
	}
	vi.reserve(100);
	cout << vi.capacity() << endl;
	vi.resize(135, 10);
	cout << vi.capacity() << endl;
	cout << vi.find(10) - vi.begin() << endl;

	Cpang::Vector<int> vi2(vi.begin() + 3, vi.begin() + 7);
	vi.swap(vi2);
	vi.insert(vi.begin() + 1, 20, 17);
	vi2.earse(vi2.begin() + 3);
	for (auto& e : vi)
	{
		cout << e << ' ';
	}
	cout << endl;
	for (auto& e : vi2)
	{
		cout << e << ' ';
	}
	cout << endl;

	Cpang::Vector<int>::reverse_iterator rit;
	for (rit = vi.rbegin(); rit != vi.rend(); rit++)
	{
		cout << *rit << ' ';
	}

	return 0;
}