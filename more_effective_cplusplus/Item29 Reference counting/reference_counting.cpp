#include <iostream>
#include <iomanip>
using namespace std;

class String {
public:
    String(const char* value = "");
    String& operator=(const String& rhs);
    //...
private:
    char* data;
};

String& String::operator=(const String& rhs) {
    if (this == &rhs) return *this;
    delete [] data;
    data = new char[strlen(rhs.data) + 1];
    strcpy(data, rhs.data);
    return *this;
}

int main(int argv, char* argc[]) {
    String a, b, c, d, e;
    a = b = c = d = e = "Hello";
    return 0;
}