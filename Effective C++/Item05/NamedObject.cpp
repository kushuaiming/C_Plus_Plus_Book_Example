#include <iostream>
using namespace std;

template<typename T>
class NamedObject {
public:
    NamedObject(const char& name, const T& value);
    NamedObject(const string& name, const T& value);
private:
    string& nameValue;
    const T objectValue;
    //string nameValue;
    //T objectValue;
};

int main(int argv, char* argc[])
{
    string newDog("Persephone");
    string oldDog("Satch");
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    // 以下代码不能通过编译
    //p = s;
    return 0;
}