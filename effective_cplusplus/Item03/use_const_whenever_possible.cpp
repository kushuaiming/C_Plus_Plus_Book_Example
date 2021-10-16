#include <iostream>
using namespace std;

class Widget;
// 两个函数里的参数效果相同
void f1(const Widget* pw);
void f2(Widget* const pw);

class TextBlock {
public:
    TextBlock(const string tmp) : text(tmp) {}
    const char& operator[](size_t position) const { // operator[] for const对象
        cout << "const" << endl;
        return text[position];
    }
    char& operator[](size_t position) { // operator[] for non-const对象,返回的是一个char引用(否则编译出错)
        cout << "non-const" << endl;
        return text[position];
        
        // 这样做是为了避免两个函数中的代码重复,另non-const版本调用const版本的函数
        /*return const_cast<char&>(// 将operator[]返回值的const转除
            static_cast<const TextBlock&>(*this)// 为*this加上const
            [position]);//调用const operator[]*/
    }
private:
    string text;
};

void print(const TextBlock& ctb) {
    cout << ctb[0] << endl;
}

class CTextBlock {
public:
    CTextBlock(char* tmpPText, size_t tmpTextLength = 0, bool isValid = false) 
        :pText(tmpPText),
        textLength(tmpTextLength),
        lengthIsValid(isValid)
    {}

    char& operator[](size_t position) const
    {
        return pText[position];
    }

    size_t length() const;
private:
    char* pText;
    // 最近一次计算的文本区块长度
    // mutable表示成员变量可能总是会被更改,即使在const成员函数内
    mutable size_t textLength;
    // 目前的长度是否有效
    mutable bool lengthIsValid;
};

size_t CTextBlock::length() const {
    if (!lengthIsValid) {
        // 错误,在const成员函数内不能赋值给textLength和lengthIsValid(不加mutable的情况下)
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

int main(int argv, char* argc[])
{
    TextBlock tb("Hello");
    cout << tb[0] << endl;

    const TextBlock ctb("World");
    cout << ctb[0] << endl;

    tb[0] = 'X'; // 没问题
    print(tb);
    //ctb[0] = 'X';// 出错

    const CTextBlock cctb("Hello");
    char* pc = &cctb[0];
    //*pc = 'J';
    cout << pc[0] << endl; // cctb现在有了"Jello"这样的内容

    return 0;
}
