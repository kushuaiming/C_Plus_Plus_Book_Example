#include <iostream>
using namespace std;

class X {
public:
    virtual void foo();
};

void X::foo() {

}

X foobar() {
    X xx;
    X* px = new X;

    xx.foo();
    px->foo();

    delete px;
    return xx;
}

void foobar(X& _result) {
    // construct _result
    // _result replaces local xx ...
    _result.X::X();

    // expand X *px = new X;
    px = _new(sizeof(X));
    if (px != 0)
        px->X::X();

    // ...
}

int main(int argc, char* argv[]) {
    return 0;
}