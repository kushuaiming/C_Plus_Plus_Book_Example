#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Bitmap {};

class Widget {
public:
    Widget& operator=(const Widget& rhs);
private:
    Bitmap* pb;// 指针,指向一个从heap分配而得的对象
};

//Widget& Widget::operator=(const Widget& rhs) {
//    if (this == &rhs) return *this; // 判断是否是自我赋值
//
//    delete pb;                      // 停止使用当前的bitmap
//    pb = new Bitmap(*rhs.pb);       // 使用rhs's bitmap的副本
//    return *this;                   // 连续赋值
//}

// 船新版本
//Widget& Widget::operator=(const Widget& rhs) {
//    Bitmap* pOrig = pb;             // 记住原先的pb
//    pb = new Bitmap(*rhs.pb);       // 另pb指向*pb的一个副本
//    delete pb;                      // 删除原先的pb
//    return *this;                   // 连续赋值
//}

// 上面版本的改进
Widget& Widget::operator=(const Widget& rhs) {
    Widget temp(rhs);
    swap(temp, *this);
    return *this;
}

int main(int argv, char* argc[]) {
    Widget w;
    w = w;// 自我赋值的情况

    vector<Widget> a(10);
    int i = 0, j = 0;
    a[i] = a[j];// 潜在的自我赋值(当i==j时)

    Widget* px;
    Widget* py;
    *px = *py;// 潜在的自我赋值(当px和py指向同一个东西时)
    return 0;
}