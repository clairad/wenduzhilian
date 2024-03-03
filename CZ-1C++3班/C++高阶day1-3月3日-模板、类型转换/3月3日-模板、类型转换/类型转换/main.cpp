#include <stdio.h>
#include <stdlib.h>

class Base {
public:
	int a;
	int b;
	
	Base(int a1 = 0, int b1 = 0) : a(a1), b(b1) {}

	virtual void print()
	{
		printf("%d %d\n", a, b);
	}
};

class Test : public Base {
public:
	int c;
	int d;

	Test(int c1 = 0, int d1 = 0) : c(c1), d(d1) {}
	Test(int a1, int b1, int c1, int d1) : Base(a1, b1), c(c1), d(d1) {}
	
	virtual void print()
	{
		printf("%d %d\n", c, d);
	}
};

class Test2{
public:
	int e;
	int f;
};

template <class T1, class T2>
void testfunc(T1* a, T2* b)
{
	b = static_cast<T1*>(a);
}

int static_cast_test()
{
	Base* b = new Base;
	Test2* t2 = new Test2;
	Test* t = new Test(1, 2);
	testfunc(t, b);
	
	delete b;
	delete t2;
	delete t;

	int* pi = static_cast<int *>(malloc(1000));
	//int** ppi = static_cast<int **>(pi);

	pi[0] = 5;
	free(pi);
	return 0;
}

int reinterpret_cast_test()
{
	int b = 9;
	int* pa = &b;
	int a = reinterpret_cast<int>(pa);
	int* pb = reinterpret_cast<int*>(a);

	printf("%d", *pb);
	return 0;
}

int const_cast_test()
{
	volatile const int i = 10;
	int* pi = const_cast<int*>(&i);
	//const int* ci = const_cast<const int*>(pi);
	*pi = 8;

	printf("%d,%d\n", i, *pi);
	return 0;
}

int dynamic_cast_test()
{
	Base* pb = new Base(1,2);
	Test* pt = new Test(3,4,5,6);
	Base* pt2pb = dynamic_cast<Base*>(pt);
	printf("%d\n", pt2pb->a);

	Test* pt2pb2pt = dynamic_cast<Test*>(pt2pb);
	printf("%d\n", pt2pb2pt->d);

	Test* pb2pt = dynamic_cast<Test*>(pb); //·µ»Ø¿ÕÖ¸Õë
	//printf("%d\n", pb2pt->c);

	delete pb;
	delete pt;
	return 0;
}

class ExpTest {
	int a;
public:
	explicit ExpTest(int i) : a(i) {}

	int getA()
	{
		return a;
	}
};

int main()
{
	ExpTest et(8);
	printf("%d", et.getA());

	return 0;
}
