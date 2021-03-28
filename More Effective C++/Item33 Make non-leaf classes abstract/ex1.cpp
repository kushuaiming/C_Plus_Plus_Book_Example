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

    *pAnimal1 = *pAnimal2; //����liz1ֻ��animal���ֱ��ı���,����취�ǽ���������Ϊvirtual
    return 0;
}