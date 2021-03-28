#include <iostream>
using namespace std;

// 写下下面代码
// class Empty {};
// 相当于写下下面代码
class Empty {
public:
    // default构造函数
    Empty() {}
    // copy构造函数
    Empty(const Empty& rhs) {}
    // 析构函数,编译器产生的是non-virtual
    ~Empty() {}
    // copy assignment 运算操作符
    Empty& operator=(const Empty& rhs) {}
};

int main(int argv, char* argc[])
{
    Empty e1;// default构造函数
    Empty e2(e1);// copy构造函数
    e2 = e1;// copy assignment 运算操作符

    return 0;
}