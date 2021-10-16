#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void printDouble(const double& rd) {
    // 不要测试rd
    cout << rd;
}

void printDouble(const double* pd) {
    // 需要测试pd是否为空
    if (pd)
        cout << *pd;
}


int main(int argv, char* argc[]) {
    
    //char* pc = 0;
    //char& rc = *pc;// 引用不能指向null

    //string& rs; // 错误,引用必须初始化
    //string s("xyzzy");
    //string& rs = s;

    // 指针可以重新赋值指向不同对象,但是应用只能指向它被初始化时的对象
    string s1("Nancy");
    string s2("Clancy");

    string& rs = s1;
    string* ps = &s1; 

    rs = s2;// rs仍然引用s1,但是s1的值变成了"Clancy"
    ps = &s2;// ps现在指向了s2
    
    return 0;
}