#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class Investment {
    //...
};

Investment* createInvestment();

/*void f() {
    Investment* pInv = createInvestment();// 调用factory函数
    //...如果这里有return语句,那么delete就不会被执行
    delete pInv;// 释放pInv所指对象
}*/

/*void f() {
    auto_ptr<Investment> pInv(createInvestment());
    //...
    //在函数结束后经由auto_ptr的析构函数自动删除pInv
}*/

void f() {
    shared_ptr<Investment> pInv1(createInvestment());
    shared_ptr<Investment> pInv2(pInv1);
    pInv1 = pInv2;
}

int main(int argv, char* argc[]) {
    
    return 0;
}