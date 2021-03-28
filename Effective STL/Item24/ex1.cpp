#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Widget {
public:
    Widget();
    Widget(double weight);
    Widget& operator=(double weight);
};

int main(int argc, char* argv[]) {
    map<int, Widget> m;
    m[1] = 1.5;
    m[2] = 3.67;
    m[3] = 10.5;
    m[4] = 45.8;
    m[5] = 0.003;
    return 0;
}
