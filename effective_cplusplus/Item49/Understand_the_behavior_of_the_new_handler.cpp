#include <iostream>
using namespace std;


// 以下是当operator new无法分配足够内存时被调用的函数
void outOfMem()
{
    cout << "Unable to satisfy request for memory\n";
    abort();
}

class X {
public:
    static void outOfMemory();
    //...
};

class Y {
public:
    static void outOfMemory();
    //...
};

class NewHandlerHoler {
public:
    // 取得目前的new-handler
    explicit NewHandlerHoler(new_handler nh) : handler(nh) {}
    // 释放它
    ~NewHandlerHoler()
    {
        set_new_handler(handler);
    }
private:
    // 记录下来
    new_handler handler;

    // 阻止copying
    NewHandlerHoler(const NewHandlerHoler&);
    NewHandlerHoler& operator=(const NewHandlerHoler&);
};

class Widget {
public:
    static new_handler set_new_handler(new_handler p) throw();
    static void* operator new(size_t size) throw(bad_alloc);
private:
    static new_handler currentHandler;
};

// static成员必须在class外被定义(除非它是const并且是整数型)
new_handler Widget::currentHandler = 0;

new_handler Widget::set_new_handler(new_handler p) throw()
{
    new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}

void* Widget::operator new(size_t size) throw(bad_alloc)
{
    // 安装Widget的new-handler
    NewHandlerHoler h(set_new_handler(currentHandler));
    // 分配内存或抛出异常
    // 恢复global new-handler.
    return::operator new(size);
}



int main(int argv, char* argc[])
{
    set_new_handler(outOfMem);
    int* pBigDataArray = new int[1000000000L];

    X* p1 = new X; // 如果分配不成功,调用X::outOfMemory
    Y* p2 = new Y; // 如果分配不成功,调用Y::outOfMemory

    // Widget的客户使用new-handling
    // 函数声明,此函数在Widget对象分配失败时被嗲用
    void outOfMem();
    // 设定outOfMem为Widget的new-handling函数
    Widget::set_new_handler(outOfMem);
    // 如果分配内存失败,调用outOfMem
    Widget* pw1 = new Widget;
    // 如果内存分配失败,调用global new-handling函数(如果有的话)
    string* ps = new string;
    // 设定Widget专属的new-handling函数为null
    Widget::set_new_handler(0);
    // 如果内存分配失败,立刻抛出异常
    Widget* pw2 = new Widget;

    return 0;
}
