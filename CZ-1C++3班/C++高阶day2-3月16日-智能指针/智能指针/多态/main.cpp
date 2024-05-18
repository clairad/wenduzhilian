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
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};


class Base {
public:
    // 声明一个虚析构函数  
    virtual ~Base() {
        std::cout << "Destroying Base\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override { // override表示覆盖基类中的虚函数  
        std::cout << "Destroying Derived\n";
    }
};

int main() {
    // 使用基类指针指向派生类对象  
    Base* basePtr = new Derived();

    // 当删除基类指针时，由于析构函数是虚的，  
    // 首先会调用派生类的析构函数，然后调用基类的析构函数  
    delete basePtr;

    return 0;
}
