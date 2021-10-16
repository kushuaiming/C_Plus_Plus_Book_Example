#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class String {
public:
    String(const char* initValue = "");
    String(const String& rhs);
    String& operator=(const String& rhs);
    ~String();
    //...
private:
    struct StringValue {
        size_t refCount;
        char* data;

        StringValue(const char* initValue = "");
        ~StringValue();
    };
    StringValue* value;
};

String::String(const char* initValue)
    : value(new StringValue(initValue))
{
}

String::String(const String& rhs)
    : value(rhs.value)
{
    ++value->refCount;
}

String& String::operator=(const String& rhs) {
    if (value == rhs.value)
        return *this;

    if (--value->refCount == 0)
        delete value;

    value = rhs.value;
    ++value->refCount;

    return *this;
}

String::~String() {
    if (--value->refCount == 0)
        delete value;
}

String::StringValue::StringValue(const char* initValue) : refCount(1) {
    data = new char[strlen(initValue) + 1];
    strcpy(data, initValue);
}

String::StringValue::~StringValue() {
    delete[] data;
}

int main(int argv, char* argc[]) {
    String s1("More Effective C++");
    String s2 = s1;
    return 0;
}