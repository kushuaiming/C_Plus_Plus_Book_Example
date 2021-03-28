#include <iostream>
using namespace std;

typedef void (*FuncPtr) ();// 函数指针
int doSomething();

int main(int argv, char* argc[]) {
    FuncPtr funcPtrArray[10];
    //funcPtrArray[0] = &doSomething;// 错误,类型不一致
    funcPtrArray[0] = reinterpret_cast<FuncPtr>(&doSomething);
    return 0;
}