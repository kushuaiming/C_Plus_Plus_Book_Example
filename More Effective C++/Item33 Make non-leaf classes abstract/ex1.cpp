#include <iostream>
using namespace std;

class Animal {
public:
    Animal& operator=(const Animal& rhs);
    //...
};

class Lizard : public Animal {
public:
    Lizard& operator=(const Lizard& rhs);
    //...
};

class Chicken : public Animal {
public:
    Chicken& operator=(const Chicken& rhs);
    //...
};

int main(int argv, char* argc[]) {
    Lizard liz1;
    Lizard liz2;

    Animal* pAnimal1 = &liz1;
    Animal* pAnimal2 = &liz2;

    //...

    *pAnimal1 = *pAnimal2; //这里liz1只有animal部分被改变了,解决办法是将函数设置为virtual
    return 0;
}