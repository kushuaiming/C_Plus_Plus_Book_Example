#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Widget {
public:
    Widget& operator=(const Widget& rhs) {// 返回类型是个reference,指向当前对象,
        return *this;// 返回左侧对象
    }
};

int main(int argv, char* argc[]) {
    int x, y, z;
    x = y = z = 15;    // 普通赋值的连锁形式
    x = (y = (z = 15));// 上面形式和这个等效
    return 0;
}