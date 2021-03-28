#include <iostream>
using namespace std;

class Widget {
    //...
};

class SpecialWidget : public Widget{
    //...
};

void update(SpecialWidget* psw);
void updateViaRef(SpecialWidget& rsw);

int main(int argv, char* argc[]) {
    SpecialWidget sw;                                // sw是一个非const变量
    const SpecialWidget& csw = sw;                   // 但是csw是一个对const的引用
    //update(&csw);                                  // 出错
    update(const_cast<SpecialWidget*>(&csw));        // 可以
    update((SpecialWidget*)&csw);                    // 和上面效果相同,但是使用C风格的转换

    Widget* pw = new SpecialWidget;
    //update(pw);                                    // 出错,pw的类型是Widget*,但是update参数类型是SpecialWidget*
    update(dynamic_cast<SpecialWidget*>(pw));        // 可以???
    updateViaRef(dynamic_cast<SpecialWidget&>(*pw)); // 可以???

    return 0;
}