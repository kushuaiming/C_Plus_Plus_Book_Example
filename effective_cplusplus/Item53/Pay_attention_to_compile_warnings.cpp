#include <iostream>
using namespace std;

// 书中说编译器会产生一个警告:
// warning: D::f() hides virtual B::f()
// 但是我的编译器成功编译没有警告

class B {
public:
    // 这里的f是一个const成员函数,但是在D中它未被声明为const
    virtual void f() const;
};

class D : public B {
public:
    virtual void f();
};

int main(int argv, char* argc[])
{
    return 0;
}