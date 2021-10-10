#include <iostream>
using namespace std;

class ZooAnimal {
public:
    ZooAnimal();
    virtual ~ZooAnimal();

    virtual void animate();
    virtual void dram();
    //...
private:
    // data necessary for ZooAnimal's
    // version of animate() and draw()
};

class Bear : public ZooAnimal {

};

int main(int argc, char* argv[]) {

    return 0;
}