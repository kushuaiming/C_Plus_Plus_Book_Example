#include <iostream>
using namespace std;

int main(int argv, char* argc[]) {

    int firstNumber = 10, secondNumber = 3;

    // 不使用类型转换
    double result0 = firstNumber / secondNumber;
    // C格式类型转换    (type)expression
    double result1 = ((double)firstNumber) / secondNumber;
    // C++格式类型转换  static_cast<type>(expression)
    double result2 = static_cast<double>(firstNumber) / secondNumber;

    cout << result0 << endl << result1 << endl << result2 << endl;
    return 0;
}