#include <iostream>
using namespace std;

template<class T>
class Array {
public:
    Array(int size);
    //...
private:
    T* data;
};

template<class T>
Array<T>::Array(int size) {
    data = new T[size];
    //...
}

int main(int argc, char* argv[]) {
    return 0;
}