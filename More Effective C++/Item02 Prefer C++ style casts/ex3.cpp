#include <iostream>
using namespace std;

typedef void (*FuncPtr) ();// ����ָ��
int doSomething();

int main(int argv, char* argc[]) {
    FuncPtr funcPtrArray[10];
    //funcPtrArray[0] = &doSomething;// ����,���Ͳ�һ��
    funcPtrArray[0] = reinterpret_cast<FuncPtr>(&doSomething);
    return 0;
}