#include <iostream>
using namespace std;

class Foo {
public:
    int val;
    Foo* pnext;
};

void foo_bar() {
    Foo bar;
    if (bar.val || bar.pnext)
        // do something
};



int main(int argc, char* argv[]) {

    return 0;
}