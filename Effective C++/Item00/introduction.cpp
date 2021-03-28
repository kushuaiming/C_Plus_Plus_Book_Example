#include <iostream>
using namespace std;

class A {
public:
    // default构造函数
    A() {};
};

class B {
public:
    // default构造函数
    // explicit可以阻止执行隐式类型转换,但是仍可以被用来进行显示类型转换
    explicit B(int x = 0, bool b = true) {};
};

class C {
public:
    // 不是default构造函数
    explicit C(int x) {};
};

void doSomething(B bObject) {};

class Widget {
public:
    Widget() {
        cout << "The Widget has been constructed." << endl;
    };// default构造函数
    Widget(const Widget& rhs) {
        cout << "copy constructor is used" << endl;
    }; // copy构造函数
    Widget& operator=(const Widget& rhs) {
        cout << "copy assignment operator is used" << endl;
        return *this;// item10:have assignment operators return a reference to *this
    };// 拷贝赋值函数
};

bool hasAcceptableQuality(Widget w) {
    return 0;
};

int main(int argv, char* argc[])
{
    B bObj1;
    doSomething(bObj1);// 没问题,传递一个B给doSomething函数
    B bObj2(28);// 没问题
    //doSomething(28);// 错误,doSomething应该接收一个B
    doSomething(B(28));// 没问题,B构造函数讲int显式转换

    Widget w1;
    Widget w2(w1);
    Widget w3 = w2;// 这里调用的是拷贝构造函数而不是拷贝赋值运算符!
    w1 = w2;
    
    Widget aWidget;
    if (hasAcceptableQuality(aWidget))// 这里调用拷贝构造函数
        cout << 0 << endl;

    //int* p = 0; // p是一个null指针
    //cout << *p << endl; // 对一个null指针取值会导致不明确的行为

    //char name[] = "XuMing"; // name是个数组,大小为7(最尾端的null)
    //char c = name[10]; // 指向一个无意义的索引,会导致不明确的行为
    //cout << c << endl;

    return 0;
}
