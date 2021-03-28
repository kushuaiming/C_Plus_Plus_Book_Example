#include <iostream>
using namespace std;

class Widget {
public:
    virtual void flip() = 0;
    //...
};

void flip(const Widget& widget) {
    widget.flip();
}

int main(int argc, char* argv[]) {

    return 0;
}