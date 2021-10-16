#include <iostream>
using namespace std;

class Name {
public:
    Name(const string& s);// 将string类型转化成Name类型
};

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1);// 将int类型转化为Rational类型
};

int main(int argc, char* argv[]) {
    return 0;
}