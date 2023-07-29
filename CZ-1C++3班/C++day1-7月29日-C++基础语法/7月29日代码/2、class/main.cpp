#include <iostream>
using namespace std;

class Cpang
{
public:
	int a;
	char c;
private:
	double b;
public:
	void setB(double s) { b = s; }
	double getB();
	void showB();
};


double Cpang::getB()
{
	return b;
}

void Cpang::showB()
{
	cout << b << endl;
}

int main()
{
	Cpang cp, cp2;
	cout << sizeof(Cpang) << endl;

	cp.a = 65;
	cp.c = 100;
	cp.setB(3.14);
	cp.showB();

	cp2.setB(6.66);
	cp2.showB();
	return 0;
}


