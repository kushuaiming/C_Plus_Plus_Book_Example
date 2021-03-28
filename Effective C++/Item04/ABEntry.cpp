#include <iostream>
#include <list>
using namespace std;

class PhoneNumber {};

// ABEntry = "Adress Book Entry"
class ABEntry {
public:
    ABEntry(const string& name, const string& address, const list<PhoneNumber>& phones);

private:
    string theName;
    string theAddress;
    list<PhoneNumber> thePhones;
    int numTimesConsulted;
};

// 使用成员初值列(member initialization list)进行初始化
// 直接在花括号里面用等于号是赋值不是初始化
ABEntry::ABEntry(const string& name, const string& address,
                 const list<PhoneNumber>& phones)
    :theName(name),
    theAddress(address),
    thePhones(phones),
    numTimesConsulted(0)
{}

int main(int argv, char* argc[])
{
    // 手动初始化
    int x = 0;
    const char* text = "A C-Style string";

    // 以读取input stream的方式进行初始化
    double d;
    cin >> d;

    return 0;
}
