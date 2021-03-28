#include <iostream>
using namespace std;

class String {
    // ...
};

int main(int argc, char* argv[]) {
    String s1 = "Hello";
    String s2 = s1; // 这里调用拷贝构造函数会导致较大的开销
    return 0;
}
