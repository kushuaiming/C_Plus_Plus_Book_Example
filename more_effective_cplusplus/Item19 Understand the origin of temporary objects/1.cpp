#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_STRING_LEN = 10;

// 找到str里面含有ch的次数
size_t countChar(const string& str, char ch) {
    int sum = 0;
    for (char c : str) {
        if (c == ch)
            sum++;
    }
    return sum;
}

void uppercasify(string& str) {
    //...
};

int main(int argv, char* argc[]) {
    char buffer[MAX_STRING_LEN];
    char c;

    // 使用setw来避免读取string时缓存溢出
    cin >> c >> setw(MAX_STRING_LEN) >> buffer;
    cout << "There are " << countChar(buffer, c)// 这里调用的时候发生了类型转换,从而产生了临时变量
         << " occurrences of the character " << c
         << " in " << buffer << endl;

    // 这里会报错
    char subtleBookPlug[] = "Effective C++";
    uppercasify(subtleBookPlug);
    return 0;
}