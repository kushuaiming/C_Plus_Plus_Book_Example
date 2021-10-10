#include <iostream>
using namespace std;

class X {
public:
    X();
    ~X();
    operator Y() const;
    X getValue();
};
class Y {
public:
    Y();
    ~Y();
    operator == (const Y&) const;
    //...
};

int main(int argc, char* argv[]) {
    X xx;
    Y yy;
    if (yy == xx.getValue()) {
        //...
    }
    return 0;
}