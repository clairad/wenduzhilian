#include <iostream>
using namespace std;

class Car
{
public :
	virtual void Drive() {}
};
class Benz :public Car
{
public :
	virtual void Drive() { cout << "Benz-����" << endl; }
};


class Base {
public:
    // ����һ������������  
    virtual ~Base() {
        std::cout << "Destroying Base\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override { // override��ʾ���ǻ����е��麯��  
        std::cout << "Destroying Derived\n";
    }
};

int main() {
    // ʹ�û���ָ��ָ�����������  
    Base* basePtr = new Derived();

    // ��ɾ������ָ��ʱ������������������ģ�  
    // ���Ȼ���������������������Ȼ����û������������  
    delete basePtr;

    return 0;
}
